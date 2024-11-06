/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:15:59 by ssoumill          #+#    #+#             */
/*   Updated: 2024/11/06 13:38:53 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data data;
	int i;

	if ((ft_check_args(argc, argv) || argc < 5 || argc > 6))
		return (printf("Bad input\n"), 1);
	if (ft_init(&data, argv, argc) == 1)
		return (1);
	if (data.nbr_philo == 1)
		return (ft_one_philo(&data), 0);
	if (ft_start_philo(&data))
		return (1);
	i = 0;
	monitor(&data, i);
	i = 0;
	while (i < data.nbr_philo)
	{
		if (pthread_join(data.philo[i].thread, NULL))
			return (1);
		i++;
	}
	ft_destroy_mutex(&data);
	free(data.philo);
	return (0);
}
