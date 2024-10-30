/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:12:39 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/26 18:15:36 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	*dst[4];
	char	*src;
	int		d[4] = {1, 2, 3, 4};

//	char	*dest;
//	char	*srcs;
//	dst[10] = 0;
//	dest[10] = 0;
//	srcs = "coucou";
	src = "salut";
	//printf("%s", ft_memcpy(dst, src, 14));
	//printf("%s", memcpy(dst, src, 12));
	memcpy(dst, d, 4);
	printf("%s", dst[0]);
	printf("%s", dst[3]);
	return (0);
}
*/
/*
int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "00000000000000000";
	int		s3[] = {1,2,3,4};

	ft_memcpy(s2,s3,sizeof(int) * 3);
	printf("%s", s2);
}
*/
