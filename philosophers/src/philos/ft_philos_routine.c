/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:47:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 17:20:23 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*ft_philos_routine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->stats->nbr_of_philo == 1)
	{
		ft_philo_monitoring(philo, FORK);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->stats->monitoring_mutex);
		if (philo->stats->simutation_should_end)
		{
			pthread_mutex_unlock(&philo->stats->monitoring_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->stats->monitoring_mutex);
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		ft_philo_monitoring(philo, THINK);
	}
	return (NULL);
}
