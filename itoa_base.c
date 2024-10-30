/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:41 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/28 16:55:04 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int	get_nelem(int n, int base)
{
	int	sign;
	int	nelem;

	nelem = 1;
	if (n < 0)
	{
		sign = 1;
		if (n == -2147483648)
			n ++;
		n = n * -1;
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

static int	get_temp(int n)
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
	unsigned int	nelem;
	unsigned int	i;
	unsigned int	temp;
	char			*str;

	nelem = get_nelem(n, base);
	str = (char *)malloc((nelem + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	temp = get_temp(n);
	i = nelem -1;
	while (i > 0)
	{
		str[i] = (temp % base) + '0';
		temp = temp / base;
		i --;
	}
	if (n < 0)
		str[0] = '-';
	else
		str[0] = (temp % base) + '0';
	if (n == -2147483648)
		str[nelem -1] = '8';
	str[nelem] = '\0';
	return (str);
}
