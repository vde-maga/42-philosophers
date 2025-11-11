/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:32:09 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/11 14:58:07 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_stats *stats, pthread_mutex_t *forks, t_philo *philo)
{
	int	i;

	if (stats)
		pthread_mutex_destroy(&stats->monitoring_mutex);
	if (forks)
	{
		i = -1;
		while (++i < stats->nbr_of_philo)
		{
			pthread_mutex_destroy(&forks[i]);
			philo[i].left_fork = NULL;
			philo[i].right_fork = NULL;
		}
		free(forks);
		forks = NULL;
	}
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
}
