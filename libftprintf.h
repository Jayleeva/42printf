/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:24:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/24 12:38:33 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# def LIBFTPRINTF_H
# include <unistd.h> 

# DEC_BASE = "0123456789"
# hex_BASE = "0123456789abcdef"
# HEX_BASE = "0123456789ABCDEF"

int	ft_printf(const char *, ...);


#endif
