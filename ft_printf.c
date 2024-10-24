/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:27:12 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/24 12:37:18 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_printf(const char *, ...)
{
	return (-1);
}

int	main()
{
	char			c = 'c';
	char			s[] = "hey";
	char			**p = ;
	int				d = ;
	int				i = -2147483648;
	unsigned int	u = 2147483647;
	hex				x = ;
	HEX				X = ;
	percent			percent = %;

	ft_printf("\n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, x, X, percent);
	printf("\n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, x, X, percent);
}
