/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:49:40 by ssoumill          #+#    #+#             */
/*   Updated: 2024/05/07 20:29:17 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	i = count * size;
	if ((size != 0 && i / size != count) || (i > INT_MAX))
		return (NULL);
	p = malloc(i);
	if (!p)
		return (NULL);
	ft_bzero(p, i);
	return (p);
}
/*
int	main(void)
{
	size_t count;
	size_t size;

	count = INT_MAX;
	size = INT_MAX;
	printf("%s\n", ft_calloc(count, size));
	printf("%s\n", calloc(count, size));
} */