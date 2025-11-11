/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:28:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/11 14:07:16 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_is_starved(t_philo *philo)
{
	int	last_meal_timestamp;

	last_meal_timestamp = ft_get_time() - philo->last_meal_time;
	if (last_meal_timestamp >= philo->stats->time_to_die)
		return (1);
	else
		return (0);
}

int	ft_philo_is_dead(t_stats *stats, t_philo *philo, int *satisfied_philos)
{
	if (stats->must_eat_times > 0
		&& philo->eaten_meals >= stats->must_eat_times)
		(*satisfied_philos)++;
	if (ft_philo_is_starved(philo) == 1)
	{
		pthread_mutex_unlock(&stats->monitoring_mutex);
		ft_philo_monitoring(philo, DEAD);
		pthread_mutex_lock(&stats->monitoring_mutex);
		stats->simulation_should_end = 1;
		pthread_mutex_unlock(&stats->monitoring_mutex);
		return (1);
	}
	return (0);
}

void	ft_monitor_simulation(t_philo *philos, t_stats *stats)
{
	int	i;
	int	satisfied_philos;

	satisfied_philos = 0;
	while (1)
	{
		i = -1;
		pthread_mutex_lock(&stats->monitoring_mutex);
		while (++i < stats->nbr_of_philo)
		{
			if (ft_philo_is_dead(stats, &philos[i], &satisfied_philos) == 1)
				return ;
		}
		if (satisfied_philos == stats->nbr_of_philo)
		{
			stats->simulation_should_end = 1;
			printf("Every Philosopher had %d meals!\n", stats->must_eat_times);
			pthread_mutex_unlock(&stats->monitoring_mutex);
		}
		pthread_mutex_unlock(&stats->monitoring_mutex);
		i++;
	}
}
