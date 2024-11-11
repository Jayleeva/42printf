/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:24:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/11 11:02:04 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "write.c"
# include "itoa.c"
# include "itoa_base.c"
# include "itoa_pointer.c"
# include <unistd.h>
# include <stdlib.h>

//# DEC_BASE = "0123456789"
//# HEX_BASE_LOW = "0123456789abcdef"
//# HEX_BASE_UP = "0123456789ABCDEF"

int	ft_printf(const char *, ...);


#endif
