/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/12 15:52:17 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putchar_fd_(char c, int fd, int result)
{
	write(fd, &c, 1);
	result ++;
	return (result);
}

int	putstr_fd_(char *s, int fd, int result)
{
	int	i;

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
	result = putstr_fd_("0x", 1, result);
	result = putstr_fd_(itoa_base(p, 16), 1, result);
	return (result);
}

int	print_unsigned(unsigned int u, char type, int result)
{
	if (type == 'u')
		result = putstr_fd_(itoa_base(u, 10), 1, result);
	if (type == 'x')
		result = putstr_fd_(itoa_base(u, 16), 1, result);
	else if (type == 'X')
		result = putstr_fd_(ft_toupper_(itoa_base(u, 16)), 1, result);
	return (result);
}