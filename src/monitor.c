/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:32:27 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/03 14:06:26 by ssoumill         ###   ########.fr       */
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
			if (data->death == 0 || data->philo->meal_eat == data->nbr_meal)
			{
				pthread_mutex_unlock(&data->print);
				break ;
			}
			if (gettime() - data->philo[i].t_last_meal > data->death_time
				&& data->philo[i].is_eating == 0)
			{
				print_death(data, i);
                pthread_mutex_unlock(&data->print);
				break ;
			}
			pthread_mutex_unlock(&data->print);
			i++;
		}
        pthread_mutex_lock(&data->print);
		if (data->death == 0 || data->finish == data->nbr_philo)
        {
            pthread_mutex_unlock(&data->print);
			break ;
        }
        pthread_mutex_unlock(&data->print);
	}
}
