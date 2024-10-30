/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:02:32 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/25 15:09:21 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	j;
	unsigned char	*str;

	str = (unsigned char *)s;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == j)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}

/* int	main(void)
{
	const void	*s;

	s = "salut la mif";
	printf("%s", ft_memchr(s, 105, 10));
	return (0);
} */
