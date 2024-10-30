/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:55:39 by ssoumill          #+#    #+#             */
/*   Updated: 2024/06/07 17:04:14 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr(long int nb, int count)
{
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= -1;
		count++;
	}
	if (nb > 9)
	{
		count = ft_putnbr(nb / 10, count);
		count = ft_putnbr(nb % 10, count);
	}
	else
	{
		nb += '0';
		ft_putchar(nb, count);
		count++;
	}
	return (count);
}

int	ft_putstr(char *str, int count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (str[i])
	{
		count = ft_putchar(str[i], count);
		i++;
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nb, int count)
{
	if (nb > 9)
	{
		count = ft_putnbr(nb / 10, count);
		count = ft_putnbr(nb % 10, count);
	}
	else
	{
		nb += '0';
		ft_putchar(nb, count);
		count++;
	}
	return (count);
}

int	ft_hexa(unsigned int nb, int count, char *base)
{
	if (nb >= 16)
	{
		count = ft_hexa(nb / 16, count, base);
		count = ft_hexa(nb % 16, count, base);
	}
	else
	{
		ft_putchar(base[nb], count);
		count++;
	}
	return (count);
}
