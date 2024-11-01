/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:42:07 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/01 16:42:16 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_struct(t_data *data, char **argv, int argc)
{
	data->finish = 0;
	data->death = 1;
	data->nbr_philo = ft_atol(argv[1]);
	data->death_time = ft_atol(argv[2]);
	data->eating_time = ft_atol(argv[3]);
	data->sleeping_time = ft_atol(argv[4]);
	pthread_mutex_init(&data->print, NULL);
	if (argc == 6)
		data->nbr_meal = ft_atol(argv[5]);
	else
		data->nbr_meal = -1;
}

static int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		(data->philo[i]).is_eating = 0;
		(data->philo[i]).is_dead = 1;
		(data->philo[i]).id = i;
		(data->philo[i]).data = data;
		(data->philo[i]).meal_eat = 0;
		if (pthread_mutex_init(&((data->philo[i]).left_fork), NULL))
			return (1);
		data->philo[i].right_fork = &data->philo[(i + 1)
			% data->nbr_philo].left_fork;
		i++;
	}
	return (0);
}

int	ft_init(t_data *data, char **argv, int argc)
{
	data->philo = malloc(sizeof(t_philo) * (ft_atol(argv[1])));
	ft_init_struct(data, argv, argc);
	if (ft_init_philo(data))
		return (1);
	return (0);
}
