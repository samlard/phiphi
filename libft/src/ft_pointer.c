/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:40:21 by ssoumill          #+#    #+#             */
/*   Updated: 2024/06/12 16:31:52 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long nb, int count, char *base)
{
	if (nb >= 16)
	{
		count = ft_pointer(nb / 16, count, base);
		count = ft_pointer(nb % 16, count, base);
	}
	else
	{
		ft_putchar(base[nb], count);
		count++;
	}
	return (count);
}
