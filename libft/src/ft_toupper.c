/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:32:44 by ssoumill          #+#    #+#             */
/*   Updated: 2024/05/06 12:37:38 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	else
		return (c);
}
/*
int	main(void)
{
	char	c;
	char	a;

	c = 'a';
	a = 'c';
	printf("%d\n", ft_toupper(c));
	printf("%d\n", ft_toupper(a));
	return (0);
} */
