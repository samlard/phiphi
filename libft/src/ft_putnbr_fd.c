/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:21:59 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 12:26:17 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	if (fd >= 0)
	{
		i = (long)n;
		if (i < 0)
		{
			write(fd, "-", 1);
			i = i * -1;
		}
		if (i > 9)
		{
			ft_putnbr_fd(i / 10, fd);
			ft_putnbr_fd(i % 10, fd);
		}
		else
		{
			i += '0';
			ft_putchar_fd(i, fd);
		}
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(2147483647, 1);
	return (0);
}
 */