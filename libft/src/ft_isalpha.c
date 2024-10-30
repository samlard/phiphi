/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:49:25 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/20 23:55:52 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	a;
	char	c;
	char	q;

	a = 'v';
	c = '/';
	q = '{';
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", ft_isalpha(q));
	return (0);
}
*/
