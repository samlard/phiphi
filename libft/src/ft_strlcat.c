/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:19:52 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 16:53:10 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_dst;
	size_t	s_src;

	i = 0;
	s_src = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s_src);
	s_dst = ft_strlen((const char *)dst);
	if (dstsize <= 0 || dstsize <= s_dst)
		return (s_src + dstsize);
	while (src[i] && i + s_dst < dstsize - 1)
	{
		dst[i + s_dst] = src[i];
		i++;
	}
	dst[i + s_dst] = '\0';
	return (s_dst + s_src);
}
/*
int	main(void)
{
	char	dst[100];

	printf("%zu\n", strlcat(dst, "", 0));
	printf("%zu", ft_strlcat(dst, "", 0));
	//printf("%s\n", dst);
}  */
