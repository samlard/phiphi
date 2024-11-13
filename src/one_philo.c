/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:26 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/13 15:26:07 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_philo(t_data *data)
{
	data->start_time = gettime();
	printf("%zu %d philosopher right fork taken\n", gettime()
		- data->start_time, data->philo->id);
	ft_usleep(data->death_time, NULL);
	printf("%zu %d philo died\n", gettime() - data->start_time,
		data->philo->id);
	ft_destroy_mutex(data, 3, 0);
}
