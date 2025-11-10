/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:29:48 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 14:54:05 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_stats(t_stats *stats, char **argv)
{
	stats->nbr_of_philo = ft_atoi(argv[1]);
	stats->time_to_die = ft_atoi(argv[2]);
	stats->time_to_eat = ft_atoi(argv[3]);
	stats->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		stats->must_eat_times = ft_atoi(argv[5]);
	else
		stats->must_eat_times = -1;
	if (stats->nbr_of_philo == 0 || stats->must_eat_times == 0)
	{
		ft_error(NULL, NULL, NULL,
			"Error: Number of Philosophers and Eat Times <= 0");
		return (1);
	}
	if (pthread_mutex_init(&stats->monitoring_mutex, NULL) != 0)
	{
		ft_error(NULL, NULL, NULL, "");
		return (1);
	}
	stats->simulation_should_end = 0;
	return (0);
}
