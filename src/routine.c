/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:38:12 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/04 16:36:34 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	if (ft_is_dead(philo->data) == 1)
		printf("%zu %d philosopher is thinking\n", gettime()
			- philo->data->start_time, philo->id);
}

void	sleeping(t_philo *philo)
{
	if (ft_is_dead(philo->data) == 1)
	{
		printf("%zu %d philosopher is sleeping\n", gettime()
			- philo->data->start_time, philo->id);
		ft_usleep(philo->data->sleeping_time, philo);
	}
}

void	eating(t_philo *philo)
{
	if (ft_is_dead(philo->data) == 1)
	{
		pthread_mutex_lock(&philo->data->l_meal);
		philo->t_last_meal = gettime();
		pthread_mutex_unlock(&philo->data->l_meal);
		printf("%zu %d philosopher is eating\n", gettime()
			- philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->data->philo_meal);
		philo->meal_eat++;
		pthread_mutex_unlock(&philo->data->philo_meal);
		ft_usleep(philo->data->eating_time, philo);
		pthread_mutex_lock(&philo->data->l_meal);
		philo->t_last_meal = gettime();
		pthread_mutex_unlock(&philo->data->l_meal);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
	}
}

void	ft_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (ft_is_dead(philo->data) == 1)
			printf("%zu %d philosopher right fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->left_fork);
		if (ft_is_dead(philo->data) == 1)
			printf("%zu %d philosopher left fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		eating(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork);
		if (ft_is_dead(philo->data) == 1)
			printf("%zu %d philosopher left fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		pthread_mutex_lock(philo->right_fork);
		if (ft_is_dead(philo->data) == 1)
			printf("%zu %d philosopher right fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		eating(philo);
	}
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (1)
	{
		if (check_philo_meal(philo) == 1)
		{
			pthread_mutex_lock(&philo->data->end);
			philo->data->finish++;
			pthread_mutex_unlock(&philo->data->end);
			break ;
		}
		if (ft_is_dead(philo->data) == 0)
			break ;
		ft_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	if (ft_end(philo->data) == 1)
	{
		printf("%zu All philo have eat %lu nbr of meal\n", gettime()
			- philo->data->start_time, philo->meal_eat);
	}
	return (NULL);
}
