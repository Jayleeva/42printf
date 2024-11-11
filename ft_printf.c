/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/11 12:09:05 by cyglardo         ###   ########.fr       */
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

int	ft_printf(const char *s, ...)
{
	va_list				args;
	int					j;
	int					result;
	unsigned long int	*address;

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
					//putnbr(va_arg(args, int), *result); //force à utiliser partout un pointeur sur result!!
					result = putstr_fd(itoa(va_arg(args, int)), 1, result);
				else if (s[j +1] == 'p' || s[j +1] == 'x' || s[j +1] == 'X')
				{
					result = putstr_fd("0x", 1, result);
					if (s[j +1] == 'p')
					{	
						address = va_arg(args, unsigned long int *);
						result = putstr_fd(itoa_pointer(address, 16), 1, result);
					}
					else if (s[j +1] == 'x')
						result = putstr_fd(itoa_base(va_arg(args, int), 16), 1, result);
					else if (s[j +1] == 'X')
						result = putstr_fd(ft_toupper(itoa_base(va_arg(args, int), 16)), 1, result);
				}
				//else if (s[j +1] == 'u')
				//	printf("%u", va_arg(args, unsigned int));
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
	printf("\n%d\n", result);
	return (result);
}

int	main(void)
{
	//char			c = 'a';
	char			s[] = "hey";
	void			*p = &s;
	//int				d = 2147483647;
	//int				i = -2147483648;
	//unsigned int	u = 4294967295;
	//int				hex = 0x2a;
	//int				HEX = 0x2B;

	//ft_printf("CUSTOM : \n> %c", c);
	ft_printf("CUSTOM : \n> %s", s);
	//ft_printf("CUSTOM : \n> %d", d);
	//ft_printf("CUSTOM : \n> %i", i);
	//ft_printf("CUSTOM : \n> %u", u);
	//ft_printf("CUSTOM : \n> %x", hex);
	//ft_printf("CUSTOM : \n> %X", HEX);
	ft_printf("CUSTOM : \n> %p", p);
	//ft_printf("CUSTOM : \n> %c \n> %s \n> %d \n> %i \n> %u \n> %x \n> %X \n> %p \n> %%", c, s, d, i, u, hex, HEX, p);
	//printf("\nOFFICIAL : \n> %x \n> %p", hex, p);
}
