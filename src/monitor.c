/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:32:27 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:16 by ssoumill         ###   ########.fr       */
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
			if (check_philo_meal(&data->philo[i]) == 0)
			{
				pthread_mutex_lock(&data->l_meal);
				if (gettime() - data->philo[i].t_last_meal > data->death_time)
				{
					pthread_mutex_unlock(&data->l_meal);
					print_death(data, i);
					break ;
				}
				pthread_mutex_unlock(&data->l_meal);
				i++;
			}
			i++;
		}
		if (ft_is_dead(data) == 0 || ft_end(data) == 1)
			break ;
	}
}
