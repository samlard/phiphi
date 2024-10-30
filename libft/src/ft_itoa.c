/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:24:48 by ssoumill          #+#    #+#             */
/*   Updated: 2024/04/29 14:56:38 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	i;
	long	nbr;

	nbr = n;
	i = ft_len(nbr);
	if (n < 0)
	{
		i++;
		nbr *= -1;
	}
	nb = malloc(sizeof(char) * (i + 1));
	if (!nb)
		return (NULL);
	nb[i] = '\0';
	while (i > 0)
	{
		i--;
		nb[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		nb[i] = '-';
	return (nb);
}
/* int	main(void)
{
	printf("%s", ft_itoa(-9874));
	return (0);
} */
