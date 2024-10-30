/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:51:09 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/23 21:04:10 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	a;

	a = (char)c;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == a)
			return (str);
		str++;
	}
	if (a == '\0')
		return (str);
	return (NULL);
}
/* 
int	main(void)
{
	const char	*s;

	s = "teste";
	printf("%s", ft_strchr(s, 357));
	return (0);
}
 */