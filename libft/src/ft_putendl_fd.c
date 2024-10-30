/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:14:18 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 12:26:05 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (fd >= 0 && s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, s + i, 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
/*
int	main(void)
{
	char	*str;

	str = "salut";
	ft_putendl_fd(str, 1);
	return (0);
}
 */