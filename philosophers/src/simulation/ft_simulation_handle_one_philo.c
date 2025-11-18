/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation_handle_one_philo.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:12:46 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/18 15:54:18 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_simulation_handle_one_philo(t_table *table)
{
	long long	time;

	time = ft_time_get_time();
	table->start_time = ft_time_get_time();
	table->philosophers[0].last_meal = table->start_time;
	ft_print_status(&table->philosophers[0], FORK_TAKEN);
	ft_time_precise_sleep(table->time_to_die);
	printf(BOLD "%4d " CYAN "%2i " RED "%16s \n" RESET, table->time_to_die,
		table->philosophers[0].id, "died");
	return (0);
}
