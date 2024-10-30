/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:38:37 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/09 18:10:01 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = malloc((i + j + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	k = -1;
	while (++k < i)
		s3[k] = s1[k];
	k = 0;
	while (k < j)
	{
		s3[i + k] = s2[k];
		k++;
	}
	s3[i + j] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (s3);
}
/*
int	main(void)
{
	const char	*s1;
	const char	*s2;

	s1 = "salut ";
	s2 = "pute ta grande mere";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}
 */