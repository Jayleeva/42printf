/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/12 16:08:38 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>


int	print_unsigned(unsigned int u, int result)
{
	result = putstr_fd_(itoa_unsigned(u, 10), 1, result);
	return (result);
}

int	print_hexbase(unsigned long long x, char type, int result)
{
	if (type == 'p')
	{
		result = putstr_fd_("0x", 1, result);
		result = putstr_fd_(itoa_base(x, 16), 1, result);
	}
	else if (type == 'x')
		result = putstr_fd_(itoa_base(x, 16), 1, result);
	else if (type == 'X')
		result = putstr_fd_(ft_toupper(itoa_base(x, 16)), 1, result);
	return (result);
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

static int	call_ft_by_type(char type, va_list args, int result)
{
	if (type == '%')
		result = putchar_fd_('%', 1, result);
	else if (type == 'c')
		result = putchar_fd_((char)va_arg(args, int), 1, result);
	else if (type == 's')
		result = putstr_fd_(va_arg(args, char *), 1, result);
	else if (type == 'd' || type == 'i')
		result = putstr_fd_(itoa_(va_arg(args, int)), 1, result);
	else if (type == 'u')
		result = print_unsigned(va_arg(args, unsigned int), result);
	else if (type == 'p' || type == 'x' || type == 'X')
		result = print_hexbase(va_arg(args, unsigned long long), type, result);
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
	while (j < ft_strlen_(s) - 1)
	{
		if (s[j] == '%')
		{
			if (is_in_set(s[j +1]) == 1)
			{
				result = call_ft_by_type(s[j +1], args, result);
				j ++;
			}
// si passes en premier, les pointeurs (dont char *?) et l'unsigned int embrouillent les prochains unsigned long long. Juste l'unsigned ou juste le pointeur passe en premier: 1er hex foire. Les deux passes en premier: les 2 hex foirent. Linverse ne semble pas etre vrai: en sens inverse, tout s'ecrit normalement, qu'il y ait quun des deux ou les deux passes en premier. Faire un free?
		}
		else
			result = putchar_fd_(s[j], 1, result);
		j ++;
	}
	va_end(args);
	printf("\n%d\n", result);
	return (result);
}

int	main(void)
{
	char			c = 'a';
	char			s[] = "hey";
	void			*p = &s;
	int				d = 2147483647;
	int				i = -2147483648;
	unsigned int	u = 4294967295;
	int				hex = 0x2a;
	int				HEX = 0x2B;

	//ft_printf("CUSTOM : \n> %a", c);
	//ft_printf("CUSTOM : \n> %s", s);
	//ft_printf("CUSTOM : \n> %p", p);
	//ft_printf("CUSTOM : \n> %d", d);
	//ft_printf("CUSTOM : \n> %i", i);
	//ft_printf("CUSTOM : \n> %u", u);
	//ft_printf("CUSTOM : \n> %x", hex);
	//ft_printf("CUSTOM : \n> %X", HEX);
	
	ft_printf("CUSTOM : \n> %c \n> %s \n> %p \n> %d \n> %i \n> %u \n> %x \n> %X \n> %%\n", c, s, p, d, i, u, hex, HEX);
	//ft_printf("CUSTOM : \n> %% \n> %p \n> %u \n> %X \n> %i \n> %x \n> %s \n> %d \n> %c\n", p, u, HEX, i, hex, s, d, c);

	//printf("\nOFFICIAL : \n> %c \n> %s \n> p \n> %d \n> %i \n> u \n> %x \n> %X \n> %%\n", c, s, d, i, hex, HEX);
}
