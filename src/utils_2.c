/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:18 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/09 18:17:24 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_usleep(long time_to_sleep, t_philo *philo)
{
	long	current_time;

	current_time = gettime();
	if (philo == NULL)
	{
		while (gettime() - current_time < time_to_sleep)
			usleep(100);
	}
	else
	{
		while (gettime() - current_time < time_to_sleep)
		{
			usleep(200);
			if (ft_is_dead(philo->data) == 0)
				break ;
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

void	ft_destroy_mutex(t_data *data, int i, int k)
{
	int j;

	j = 0;
	while (j <= i)
	{
		pthread_mutex_destroy(&data->tab[j]);
		j++;
	}
	free(data->tab);
	i = 0;
	while (i <= k)
	{
		pthread_mutex_destroy(&data->philo[i].left_fork);
		i++;
	}
	free(data->philo);
}
