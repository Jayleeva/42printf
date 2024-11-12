/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:41 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/12 16:05:49 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_nelem_(int n)
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
	while (n > 9)
	{
		nelem ++;
		n = n / 10;
	}
	return (nelem + sign);
}

static int	get_temp_(int n)
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

char	*itoa_(int n)
{
	char	*str;
	int		nelem;
	int		k;
	int		temp;

	nelem = get_nelem_(n);
	str = (char *)malloc((nelem + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	temp = get_temp_(n);
	k = nelem -1;
	while (k > 0)
	{
		str[k] = (temp % 10) + '0';
		temp = temp / 10;
		k --;
	}
	if (n < 0)
		str[0] = '-';
	else
		str[0] = (temp % 10) + '0';
	if (n == -2147483648)
		str[nelem -1] = '8';
	str[nelem] = '\0';
	return (str);
}
