/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:16:32 by ssoumill          #+#    #+#             */
/*   Updated: 2024/10/29 18:54:34 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_num(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	long	c;

	i = 1;
	while (i < argc)
	{
        if (ft_atol(argv[1]) == 1)
            return(1);
        if (is_num(argv[i]))
            return (1);
        c = ft_atol(argv[i]);
		if (c < 0)
			return (1);
		i++;
	}
	return (0);
}

