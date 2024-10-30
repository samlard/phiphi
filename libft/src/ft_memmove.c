/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:23:59 by ssoumill          #+#    #+#             */
/*   Updated: 2024/05/10 17:43:34 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*srcs;

	i = 0;
	dest = (char *)dst;
	srcs = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = srcs[len];
	}
	else
	{
		while (len--)
		{
			dest[i] = srcs[i];
			i++;
		}
	}
	return (dst);
}
/* 
int	main(void)
{
	char	str[] = "lorem ipum dolor sit a";
	//char	dest[] = "                         ";

	memmove(str, str, 4);
	// ft_memmove(dest, str, 8);
	printf("%s\n", str);
	return (0);
}
  */