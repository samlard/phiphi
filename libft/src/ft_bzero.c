/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:08:43 by ssoumill          #+#    #+#             */
/*   Updated: 2024/05/09 18:05:24 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	int	str[] = {1, 2, 3, 4};
	int	s[] = {1, 2, 3, 4};

	ft_bzero(str, 8);
	bzero(s, 8);
	printf("%d", str[0]);
	printf("%d", str[1]);
	printf("%d", str[2]);
	printf("%d\n", str[3]);
	printf("%d", s[0]);
	printf("%d", s[1]);
	printf("%d", s[2]);
	printf("%d", s[3]);
	return (0);
}
*/
