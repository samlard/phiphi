/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:32:27 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/04 14:49:16 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *data, int i)
{
	while (1)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			pthread_mutex_lock(&data->print);
			if (data->philo->meal_eat == data->nbr_meal)
				{
					pthread_mutex_unlock(&data->print);
					break;
				}
				pthread_mutex_unlock(&data->print);
			if (ft_end(data) == 1)
				break ;
			pthread_mutex_lock(&data->meal);
			if (gettime() - data->philo[i].t_last_meal > data->death_time)
			{
				pthread_mutex_unlock(&data->meal);
				print_death(data, i);
				//pthread_mutex_unlock(&data->meal);
				break ;
			}
			pthread_mutex_unlock(&data->meal);
			i++;
		}
		if (ft_is_dead(data) == 0 || ft_end(data) == 1)
			break ;
	}
}
