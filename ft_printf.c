/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/28 16:55:00 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	putchar_fd(char c, int fd, int result)
{
	write(fd, &c, 1);
	result ++;
	return (result);
}

int	putstr_fd(char s, int fd, int result)
{
	int	i;

	i = 0;
	while (s[i])
	{
		putchar_fd(s[i], fd, result);
		i ++;
	}
	return (result);
}

int	is_in_set(char c)
{
	int		i;
	char	*set;

	set = (char *)malloc((9 + 1) * sizeof(char));
	if (set == NULL)
		return (NULL);
	set = "cspdiuxX%";
	i = 0;
	while (set[i++])
	{
		if (set[i] == c)
		{
			free(set);
			return (1);
		}
	}
	free(set);
	return (0);
}

int	sort(char c, va_list args, int result)	
{
	int	base;

	if (c == "%")
		result = putchar_fd("%", 1, result);
	else if (c == "d" || c == "i")
		result = putstr_fd(itoa_base(va_arg(args, int), 10), 1, result);
	else if (c == "u")
		result = putstr_fd(itoa_base((int)va_arg(args, unsigned int), 10), 1, result);
	else if (c == "x" || c == "X")
		result = putstr_fd(itoa_base(va_arg(args, int), 16), 1 result);
	else if (c == "c")
		result = putchar_fd(va_arg(args, char), 1, result);
	else if (c == "s")
		result = putstr_fd(va_arg(args, char *), 1, result);
	else if (c == "p");
		result = putstr_fd((char *)&va_arg(args, void*), 1, result);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, s);
	result = 0;
	i = 1;
	while (s[i])
	{
		if (s[i -1] == "%")
		{
			if (is_in_set(s[i]) == 1)
			   result = sort(s[i], args, result);
			else
				return (-1);
		}
		else
			result = putchar_fd(s[i -1], 1, result);
		i ++;
	}
	va_end(args);
	//if () si types % et args correspondent pas, ou pas le bon nombre d'args?
	//	return (-1);
	return (result);
}

int	main(void)
{
	char			c = 'c';
	char			s[] = "hey";
	void			*p = &s;
	//void				p[] = {0, 1, 2, 3};
	int				d = 0;
	int				i = -2147483648;
	unsigned int	u = 2147483647;
	int				hex = 0xf;
	int				HEX = 0xF;

	ft_printf("CUSTOM : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);
	printf("OFFICIAL : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);
}
