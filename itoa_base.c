/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:41 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/11 11:13:55 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_nelem_base(int n, int base)
{
	int	sign;
	int	nelem;

	nelem = 1;
	if (n < 0)
	{
		sign = 1;
		if (n == -2147483648) // 0x80000000
			n ++;
		n = n * -1;
		//printf("\n<< %i >>\n", n);
	}
	else
		sign = 0;
	while (n > base -1)
	{
		nelem ++;
		n = n / base;
	}
	return (nelem + sign);
}

static int	get_temp_base(int n)
{
	int	temp;

	temp = n;
	if (n < 0)
	{
		if (n == -2147483648)
			temp ++;
		temp = temp * -1;
	}
	return (temp);
}

char	*itoa_base(int n, int base)
{
	char	*str;
	int		nelem;
	int		k;
	int		temp;
	
	nelem = get_nelem_base(n, base);
	str = (char *)malloc((nelem + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	temp = get_temp_base(n);
	k = nelem -1;
	while (k > 0)
	{
		str[k] = (temp % base) + '0';
		temp = temp / base;
		k --;
	}
	if (n < 0)
		str[0] = '-';
	else
		str[0] = (temp % base) + '0';
	if (n == -2147483648)
	{
		str[nelem -1] = '8';
		//printf("\n<< %s >>\n", str);
	}
	str[nelem] = '\0';
	return (str);
}
