/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:41 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/11 12:08:03 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_nelem_pointer(unsigned long int *n, unsigned long int base)
{
	int		nelem;

	nelem = 1;
	while (*n > base -1)
	{
		nelem ++;
		*n = *n / base;
	}
	return (nelem);
}

char	*itoa_pointer(unsigned long int *n, unsigned long int base)
{
	char			*str;
	int				nelem;
	int				k;

	nelem = get_nelem_pointer(n, base);
	str = (char *)malloc((nelem + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	k = nelem -1;
	while (k > 0)
	{
		str[k] = (*n % base) + '0';
		*n = *n / base;
		k --;
	}
	str[0] = (*n % base) + '0';
	str[nelem] = '\0';
	return (str);
}
