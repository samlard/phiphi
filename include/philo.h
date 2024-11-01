/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:09:23 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/01 16:41:56 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "ft_printf.h"
# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					finish;
	long				nbr_philo;
	long				death_time;
	long				eating_time;
	long				sleeping_time;
	long				nbr_meal;
	long				start_time;
	int					death;
	pthread_mutex_t		print;
	t_philo				*philo;
}						t_data;

typedef struct s_philo
{
	t_data				*data;
	int					is_eating;
	long				t_last_meal;
	int					is_dead;
	int					id;
	long			    meal_eat;
	pthread_t			thread;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
}						t_philo;

int						ft_check_args(int argc, char **argv);
int						ft_init(t_data *data, char **argv, int argc);
int						ft_start_philo(t_data *data);
long					ft_atol(const char *str);
void					*routine(void *void_philo);

#endif