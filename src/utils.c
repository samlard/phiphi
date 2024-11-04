/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:27:37 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/04 13:03:12 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
long	ft_atol(const char *str)
{
	long	i;
	long	signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}

void	print_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->is_he_dead);
	data->death = 0;
	printf("%zu philo %d is dead\n", gettime() - data->start_time,
		data->philo[i].id);
	pthread_mutex_unlock(&data->is_he_dead);
}

void	ft_usleep(long time_to_sleep, t_philo *philo)
{
	long	current_time;

	current_time = gettime();
	if (philo == NULL)
	{
		while (gettime() - current_time < time_to_sleep)
			usleep(200);
	}
	else
	{
		while (gettime() - current_time < time_to_sleep)
		{
			usleep(200);
			if (ft_is_dead(philo->data) == 0)
				break;
		}
	}
}

long	gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error in time external function!\n");
		return ((long)-1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
