/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:12:01 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/17 10:43:54 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitor_check_simulation_end(t_table *table)
{
	if (table->must_eat != -1 && ft_monitor_philo_all_ate_enought(table) != 0)
	{
		pthread_mutex_lock(&table->death_mutex);
		table->someone_died = 1;
		pthread_mutex_unlock(&table->death_mutex);
		printf("Every Philosopher had " GREEN "%d" RESET " meals\n",
			table->must_eat);
		return (1);
	}
	return (0);
}

void	*ft_monitor_routine(void *table_void)
{
	t_table	*table;
	int		i;

	table = (t_table *)table_void;
	while (1)
	{
		i = -1;
		while (++i < table->num_philos)
		{
			if (ft_monitor_check_philosopher_is_death(table, i) == 1)
				return (NULL);
		}
		if (ft_monitor_check_simulation_end(table) == 1)
			return (NULL);
		usleep(50);
		if (ft_monitor_philo_check_someone_died(table) == 1)
			return (NULL);
	}
}
