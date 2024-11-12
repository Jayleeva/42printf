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
#include <unistd.h>

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

int	ft_strlen_(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_toupper(char *s)
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
