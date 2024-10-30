/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:11:54 by ssoumill          #+#    #+#             */
/*   Updated: 2024/05/10 15:35:16 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static char	*ft_word(char const *s, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_lenword(s, c) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_lenword(s, c) && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			str[i] = ft_word(s, c);
			if (str[i] == NULL)
				return (ft_free(str, i), NULL);
			i++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	str[i] = 0;
	return (str);
}
/*
int	main(void)
{
	char	**strs;
	int		i;

	strs = ft_split("xputexputex", 'x');
	i = 0;
	while (strs[i])
	{
		printf("<%s>\n", strs[i++]);
	}
	printf("<%s>", strs[i]);
	return (0);
}
 */
