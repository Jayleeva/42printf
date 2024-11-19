/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:24:08 by cyglardo          #+#    #+#             */
/*   Updated: 2024/11/19 16:31:15 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
char	*itoa_(int n);
char	*itoa_base(unsigned long long n, unsigned long long base);
int		putchar_fd_(char c, int fd, int result);
int		putstr_fd_(char *s, int fd, int result);
int		print_pointer(unsigned long long p, int result);
int		print_unsigned(unsigned int u, char type, int result);

#endif
