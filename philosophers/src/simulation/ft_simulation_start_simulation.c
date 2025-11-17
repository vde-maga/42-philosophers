/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation_start_simulation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:01:30 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/14 14:33:47 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_simulation_start_simulation(t_table *table)
{
	pthread_t	monitor;
	int			i;

	table->start_time = ft_time_get_time();
	i = -1;
	while (++i < table->num_philos)
	{
		table->philosophers[i].last_meal = table->start_time;
		if (pthread_create(&table->philosophers[i].thread, NULL,
				ft_philo_routine, &table->philosophers[i]) != 0)
			return (ft_error(table, "Thread Creation Failed"));
	}
	if (pthread_create(&monitor, NULL, ft_monitor_routine, table) != 0)
		return (ft_error(table, "Monitor Thread Creation Failed"));
	i = -1;
	while (++i < table->num_philos)
		pthread_join(table->philosophers[i].thread, NULL);
	pthread_join(monitor, NULL);
	return (0);
}
