/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:40 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 15:43:50 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s;
	char		*t;
	char		*u;

	s = "salut";
	t = "pute";
	u = "dick";
	printf("%zu\n", ft_strlen(s));
	printf("%zu\n", ft_strlen(t));
	printf("%zu\n", ft_strlen(u));
	return (0);
}
*/
