/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:12:45 by ssoumill          #+#    #+#             */
/*   Updated: 2024/06/12 16:32:27 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c, int count);
int	ft_putnbr(long int nb, int count);
int	ft_putstr(char *str, int count);
int	ft_putnbr_u(unsigned int nb, int count);
int	ft_hexa(unsigned int nb, int count, char *base);
int	ft_pointer(unsigned long long nb, int count, char *base);
int	ft_printf(const char *str, ...);

#endif
