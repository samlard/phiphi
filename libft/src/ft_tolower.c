/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:48:16 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/23 20:50:01 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}
/*
int	main(void)
{
	char	c;
	char	a;

	c = 'A';
	a = 'C';
	printf("%d\n", ft_tolower(c));
	printf("%d\n", ft_tolower(a));
	return (0);
}
 */