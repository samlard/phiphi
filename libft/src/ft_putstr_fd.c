/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:09:46 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 12:26:28 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
	}
}

/* int	main(void)
{
	char	*str;

	str = "salut";
	ft_putstr_fd(str, 1);
	return (0);
}
 */