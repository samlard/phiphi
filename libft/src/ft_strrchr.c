/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:33:34 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 16:52:58 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	int				len;
	unsigned char	t;

	len = ft_len(s);
	str = (char *)s;
	t = (unsigned char)c;
	str += len;
	while (len >= 0)
	{
		if (*str == t)
			return (str);
		str--;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s;

	s = "slu";
	printf("%s", ft_strchr(s, 'a'));
	return (0);
} */
