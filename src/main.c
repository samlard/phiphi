/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:15:59 by ssoumill          #+#    #+#             */
/*   Updated: 2024/10/29 12:58:28 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;

    if ((ft_check_args(argc, argv) || argc < 5 || argc > 6))
        return (printf("Passe moi les scoobiscuits !\n"), 1);
    if (ft_init(&data, argv, argc))
        return 1;
    if (ft_start_philo(&data))
        return 1;
    return (0);
}