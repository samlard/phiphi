/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:38:12 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/01 16:44:33 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		while (philo->data->death && gettime() - current_time < time_to_sleep)
			usleep(200);
	}
}

void	thinking(t_philo *philo)
{
	if (philo->data->death)
		printf("%zu %d philosopher is thinking\n", gettime()
			- philo->data->start_time, philo->id);
}
void	sleeping(t_philo *philo)
{
	if (philo->data->death == 1)
	{
		printf("%zu %d philosopher is sleeping\n", gettime()
			- philo->data->start_time, philo->id);
		ft_usleep(philo->data->sleeping_time, philo);
	}
}

// int	check_death(t_philo *philo)
// {
// 	if (gettime() - philo->t_last_meal > philo->data->death_time)
// 	{
// 		if (philo->data->death == 1)
// 			printf("%zu philo %i died\n", gettime() - philo->data->start_time,
// 				philo->id);
// 		philo->is_dead = 0;
// 		return (1);
// 	}
// 	return (0);
// }
void	eating(t_philo *philo)
{
	if (philo->data->death == 1)
	{
		philo->is_eating = 1;
		philo->t_last_meal = gettime();
		if (philo->data->death)
		{
			printf("%zu %d philosopher is eating\n", gettime()
				- philo->data->start_time, philo->id);
			philo->meal_eat++;
			ft_usleep(philo->data->eating_time, philo);
			pthread_mutex_lock(&philo->data->print);
			philo->t_last_meal = gettime(); // voir quand renitialise
			philo->is_eating = 0;
			pthread_mutex_unlock(&philo->data->print);
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(&philo->left_fork);
		}
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
		if (philo->data->death)
			printf("%zu %d philosopher right fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->left_fork);
		if (philo->data->death)
			printf("%zu %d philosopher left fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		eating(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork);
		if (philo->data->death)
			printf("%zu %d philosopher left fork taken\n", gettime()
				- philo->data->start_time, philo->id);
		pthread_mutex_lock(philo->right_fork);
		if (philo->data->death)
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
		if (philo->meal_eat == philo->data->nbr_meal)
		{
			philo->data->finish++;
			//printf("%zu philo %d FINI DE MANGER\n\n", gettime()
			//	- philo->data->start_time, philo->id);
			break ;
		}
	/* 	if (philo->is_dead == 0)
			printf("%zu philo %d is dead\n", gettime()
				- philo->data->start_time, philo->id); */
		if (!philo->data->death)
		{
			//printf("%zu philo %d is dead ET ON EST DANS LA CONDITION BREAK\n\n",
			//	gettime() - philo->data->start_time, philo->id);
			break ;
		}
		ft_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	if (philo->data->finish == philo->data->nbr_philo)
		printf("%zu All philo have eat %lu nbr of meal\n", gettime()
			- philo->data->start_time, philo->meal_eat);
	return (NULL);
}

int	ft_start_philo(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = gettime();
	while (i < data->nbr_philo)
	{
		data->philo[i].t_last_meal = data->start_time;
		if (pthread_create(&(data->philo[i].thread), NULL, &routine,
				&data->philo[i]))
			return (1);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			
			if (data->death == 0)
			break ;
			if (data->philo->meal_eat == data->nbr_meal)
			 	break;
			pthread_mutex_lock(&data->print);
			if (gettime() - data->philo[i].t_last_meal > data->death_time && data->philo[i].is_eating == 0)
			{
				data->philo[i].is_dead = 0;
				data->death = 0;
				if (data->philo[i].is_dead == 0)
					printf("%zu philo %d is dead\n", gettime()
					- data->start_time, data->philo[i].id);
				pthread_mutex_unlock(&data->print);
				break ;
			}
			pthread_mutex_unlock(&data->print);
			i++;
		}
		if (data->death == 0 || data->finish == data->nbr_philo)
			break ;
		// ft_usleep(10, NULL);
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

/* while (1)
	{
		// i = 0;
		// while (i < data->nbr_philo)
		// {
		// if (data->finish == data->nbr_philo)
		// 	break ;
		// if (data->philo->meal_eat != data->nbr_meal)
		// {
			pthread_mutex_lock(&data->print);
			if (gettime() - data->philo->t_last_meal > data->death_time)
			{
				printf("%zu %d philosopher dead\n", gettime()
					- data->start_time, data->philo->id);
				printf("%zu %d philosopher last meal et j ai manger %ld\n",
					gettime() - data->philo->t_last_meal, data->philo->id,
					data->philo->meal_eat);
				// pthread_mutex_unlock(&data->print);
				data->death = 0;
				// break ;
			}
			pthread_mutex_unlock(&data->print);
			ft_usleep(10, NULL);
		// }
		// 	i++;
		// }
		if (data->death == 0 || data->finish == data->nbr_philo)
			break ;
		ft_usleep(10, NULL);
	}
	if (data->finish == data->nbr_philo)
		printf("%zu All philo have eat %lu nbr of meal\n", gettime()
			- data->start_time, data->philo->meal_eat); */