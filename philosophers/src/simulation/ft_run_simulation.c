/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:06:51 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 18:46:36 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_run_simulation(t_stats *stats, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < stats->nbr_of_philo)
	{
		philos[i].start_time = ft_get_time();
		if (pthread_create(&philos[i].t_id, NULL, ft_philos_routine,
				(void *)&philos[i]) != 0)
		{
			ft_error(stats, forks, philos, "Error: Failed to Create a Thread");
			return (1);
		}
	}
	ft_monitor_simulation(philos, stats);
	i = -1;
	while (++i < stats->nbr_of_philo)
	{
		if (pthread_join(philos[i].t_id, NULL) != 0)
		{
			ft_error(stats, forks, philos, "Error: Failed to join a Thread");
			return (1);
		}
	}
	return (0);
}
