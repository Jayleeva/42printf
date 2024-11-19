/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/14 12:39:55 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

static int	is_in_set(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX%%";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static int	call_ft_by_type(char type, va_list list, int result)
{
	char	*str;

	if (type == '%')
		result = putchar_fd_('%', 1, result);
	else if (type == 'c')
		result = putchar_fd_((char)va_arg(list, int), 1, result);
	else if (type == 's')
		result = putstr_fd_(va_arg(list, char *), 1, result);
	else if (type == 'd' || type == 'i')
	{
		str = itoa_(va_arg(list, int));
		result = putstr_fd_(str, 1, result);
		free (str);
	}
	else if (type == 'u' || type == 'x' || type == 'X')
		result = print_unsigned(va_arg(list, unsigned int), type, result);
	else if (type == 'p')
		result = print_pointer(va_arg(list, unsigned long long), result);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		j;
	int		result;

	va_start(args, s);
	result = 0;
	j = 0;
	while (j < ft_strlen_(s))
	{
		if (s[j] == '%')
		{
			j ++;
			if (is_in_set(s[j]) == 1)
				result = call_ft_by_type(s[j], args, result);
		}
		else
			result = putchar_fd_(s[j], 1, result);
		j ++;
	}
	va_end(args);
	return (result);
}
