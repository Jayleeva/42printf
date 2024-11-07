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

int	is_in_set(char c)
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


int	call_ft_by_type(char c, va_list args, int result)	
{
	//void	*p_temp;

	if (c == '%')
		result = putchar_fd('%', 1, result);
	else if (c == 'c')
		result = putchar_fd((char)va_arg(args, int), 1, result);
	else if (c == 's')
		result = putstr_fd(va_arg(args, char *), 1, result);
	/*else if (c == 'p') //faire un itoa?
	{
		p_temp = va_arg(args, void *);
		printf("Debug: %p\n", p_temp);
		result = putstr_fd((char *)&p_temp, 1, result);
	}*/
	else if (c == 'd' || c == 'i')
		result = putstr_fd(itoa_base(va_arg(args, int), 10), 1, result);
	//else if (c == 'u')
	//	result = putstr_fd(itoa_base((int)va_arg(args, unsigned int), 10), 1, result);
	//else if (c == 'x')
	//	result = putstr_fd(itoa_base(va_arg(args, int), 16), 1, result);
	//else if (c == 'X')
	//	result = putstr_fd(ft_toupper(itoa_base(va_arg(args, int), 16), 1, result));
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
	while (j < ft_strlen(s) - 1)
	{
		if (s[j] == '%')
		{
			if (is_in_set(s[j +1]) == 1)
			{
				if (s[j +1] == '%')
					result = putchar_fd('%', 1, result);
				else if (s[j +1] == 'c')
					result = putchar_fd((char)va_arg(args, int), 1, result);
				else if (s[j +1] == 's')
					result = putstr_fd(va_arg(args, char *), 1, result);
				else if (s[j +1] == 'd' || s[j +1] == 'i')
					printf("%d", s[j + 1]);
					//result = putstr_fd(itoa_base(va_arg(args, int), 10), 1, result);
				//result = call_ft_by_type(s[i +1], args, result);
				j ++;
			}
			else
				return (-1);
		}
		else
			result = putchar_fd(s[j], 1, result);
		j ++;
	}
	va_end(args);
	//if () si types % et args correspondent pas, ou pas le bon nombre d'args?
	//	return (-1);
	printf("\n%d\n", result);
	return (result);
}

int	main(void)
{
	char			c = 'a';
	//char			c2 = 'b';
	char			s[] = "hey";
	void			*p = &s;
	int				d = 35;
	int				i = 42;
	unsigned int	u = 2147483647;
	int				hex = 0x2a;
	int				HEX = 0x2A;

	ft_printf("CUSTOM : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);
	//ft_printf("CUSTOM : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);
	//printf("\nOFFICIAL : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);
}