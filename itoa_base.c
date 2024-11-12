/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:41 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/12 15:36:02 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_nelem_base(unsigned long long n, unsigned long long base)
{
	int					nelem;

	nelem = 0;
	while (n > 0)
	{
		nelem ++;
		n = n / base;
	}
	return (nelem);
}

char	*itoa_base(unsigned long long n, unsigned long long base)
{
	char					*str;
	int						nelem;
	int						k;

	nelem = get_nelem_base(n, base);
	str = (char *)malloc((nelem + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	k = nelem -1;
	while (n > 0)
	{
		if (n % base > 9)
			str[k] = n % base + 'a' - 10;
		else if (n % base < 10)
			str[k] = n % base + '0';
		n = n / base;
		k --;
	}
	str[nelem] = '\0';
	return (str);
}
