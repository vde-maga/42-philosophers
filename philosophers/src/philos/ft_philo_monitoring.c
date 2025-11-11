/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_monitoring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:19:10 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/11 14:16:01 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_monitoring(t_philo *philo, t_event_id event_id)
{
	suseconds_t	timestamp;
	const char	*events[6] = {DEAD_MSG, EAT_MSG, THINK_MSG, SLEEP_MSG, FORK_MSG,
		DROP_MSG};

	pthread_mutex_lock(&philo->stats->monitoring_mutex);
	if (philo->stats->simulation_should_end == 1)
	{
		pthread_mutex_unlock(&philo->stats->monitoring_mutex);
		return ;
	}
	timestamp = ft_get_time() - philo->start_time;
	printf(BLUE "Timestamp: %ld " RESET, timestamp);
	printf(YELLOW "Philosopher: %d " RESET, philo->philo_nbr);
	printf(GREEN "Action: %s\n"RESET, events[event_id]);
	pthread_mutex_unlock(&philo->stats->monitoring_mutex);
}
