/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:56:47 by ssoumill          #+#    #+#             */
/*   Updated: 2024/05/07 17:47:41 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* void	add_one(unsigned int i, char *t)
{
	char	*s;
	char	*t;

	(void)i;
	printf("bite %d\n", i);
} */
/*
int	main(void)
{
	s = "salut";
	t = "coucou";
	ft_striteri(s, add_one);
	printf("%s\n", s);
	return (0);
}
*/
