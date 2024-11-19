/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/19 16:43:53 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_fd_(char c, int fd, int result)
{
	write(fd, &c, 1);
	result ++;
	return (result);
}

int	putstr_fd_(char *s, int fd, int result)
{
	int	i;

	if (s == NULL)
	{
		result = putstr_fd_("(null)", 1, result);
		return (result);
	}
	i = 0;
	while (s[i])
	{
		result = putchar_fd_(s[i], fd, result);
		i ++;
	}
	return (result);
}

static char	*ft_toupper_(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
		i ++;
	}
	return (s);
}

int	print_pointer(unsigned long long p, int result)
{
	char	*str;

	if (p == 0)
		result = putstr_fd_("0x0", 1, result);
	else
	{
		result = putstr_fd_("0x", 1, result);
		str = itoa_base(p, 16);
		result = putstr_fd_(str, 1, result);
		free (str);
	}
	return (result);
}

int	print_unsigned(unsigned int u, char type, int result)
{
	char	*str;

	str = 0;
	if (u == 0)
		result = putchar_fd_('0', 1, result);
	else
	{
		if (type == 'u')
		{
			str = itoa_base(u, 10);
			result = putstr_fd_(str, 1, result);
		}
		else if (type == 'x')
		{
			str = itoa_base(u, 16);
			result = putstr_fd_(str, 1, result);
		}
		else if (type == 'X')
		{
			str = itoa_base(u, 16);
			result = putstr_fd_(ft_toupper_(str), 1, result);
		}
		free (str);
	}
	return (result);
}
