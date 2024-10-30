/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:14:38 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 15:06:51 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s))
		len = 0;
	if (ft_strlen_gnl(s) - start < len)
		len = ft_strlen_gnl(s) - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr_gnl(char *s, int c)
{
	char	a;

	if (!s)
		return (NULL);
	a = (char)c;
	if (a == '\0')
		return (s);
	while (*s != '\0')
	{
		if (*s == a)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen_gnl(s1);
	j = ft_strlen_gnl(s2);
	s3 = malloc((i + j) * sizeof(char) + 1);
	if (!s3)
		return (ft_free(&s1), NULL);
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
	return (ft_free(&s1), s3);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
