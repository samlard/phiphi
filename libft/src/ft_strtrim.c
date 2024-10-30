/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:31:13 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 12:27:22 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

static size_t	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	count;

	i = 0;
	count = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (is_set(s1[i], set) == 1 && s1[i])
	{
		count++;
		i++;
	}
	end = ft_strlen(s1) - 1;
	while (is_set(s1[end], set) == 1 && end > 0 && end > i)
	{
		count++;
		end--;
	}
	return (count);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (is_set(s1[i], set) == 1 && s1[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	start;
	size_t	i;
	char	*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = ft_start(s1, set);
	count = ft_size(s1, set);
	s2 = malloc(sizeof(char) * (ft_strlen(s1) - count) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(s1) - count))
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
int	main(void)
{
	char const	*s1;
	char const	*set;

	s1 = "";
	set = "";
	printf("%s", ft_strtrim(s1, set));
	return (0);
}
 */