/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:42:32 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/17 10:52:13 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitor_check_philosopher_is_death(t_table *table, int i)
{
	long long	time;

	pthread_mutex_lock(&table->last_meal_mutex);
	time = ft_time_diff(table->philosophers[i].last_meal, ft_time_get_time());
	pthread_mutex_unlock(&table->last_meal_mutex);
	if (time >= table->time_to_die)
	{
		pthread_mutex_lock(&table->death_mutex);
		if (table->someone_died == 0)
		{
			table->someone_died = 1;
			pthread_mutex_lock(&table->print_mutex);
			printf(BOLD "%4lld " RESET CYAN "%2i " RESET RED "%16s \033[0m\n" RESET,
				ft_time_diff(table->start_time, ft_time_get_time()),
				table->philosophers[i].id, "died");
			pthread_mutex_unlock(&table->print_mutex);
		}
		pthread_mutex_unlock(&table->death_mutex);
		return (1);
	}
	return (0);
}

int	ft_monitor_philo_check_someone_died(t_table *table)
{
	int	died_flag;

	pthread_mutex_lock(&table->death_mutex);
	died_flag = table->someone_died;
	pthread_mutex_unlock(&table->death_mutex);
	return (died_flag);
}

int	ft_monitor_philo_all_ate_enought(t_table *table)
{
	int	i;
	int	finished;

	if (table->must_eat == -1)
		return (0);
	finished = 0;
	i = -1;
	while (++i < table->num_philos)
	{
		if (table->philosophers[i].meals_eaten >= table->must_eat)
			finished++;
	}
	return (finished == table->num_philos);
}
