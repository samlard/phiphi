/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:27:37 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/06 13:40:29 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->philo_meal);
	if (philo->meal_eat == philo->data->nbr_meal)
	{
		pthread_mutex_unlock(&philo->data->philo_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->philo_meal);
	return (0);
}
int	ft_end(t_data *data)
{
	pthread_mutex_lock(&data->end);
	if (data->finish == data->nbr_philo)
	{
		pthread_mutex_unlock(&data->end);
		return (1);
	}
	pthread_mutex_unlock(&data->end);
	return (0);
}

int	ft_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->is_he_dead);
	if (data->death == 1)
	{
		pthread_mutex_unlock(&data->is_he_dead);
		return (1);
	}
	pthread_mutex_unlock(&data->is_he_dead);
	return (0);
}

void	print_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->is_he_dead);
	data->death = 0;
	printf("%zu philo %d is dead \n", gettime() - data->start_time,
		data->philo[i].id);
	pthread_mutex_unlock(&data->is_he_dead);
}

int