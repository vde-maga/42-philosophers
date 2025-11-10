/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:14:41 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 15:28:40 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

suseconds_t	ft_get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

t_philo	*ft_init_philos(t_stats *stats, pthread_mutex_t *forks)
{
	t_philo	*philos;
	int		i;

	philos = malloc(stats->nbr_of_philo * sizeof(t_philo));
	if (!philos)
		ft_error(stats, forks, NULL,
			"Error: Memory Allocation of Philos Failed");
	i = 0;
	while (i < stats->nbr_of_philo)
	{
		philos[i].philo_nbr = i + 1;
		philos[i].eaten_meals = 0;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % stats->nbr_of_philo];
		philos[i].last_meal_time = ft_get_time();
		philos[i].stats = stats;
		i++;
	}
	return (philos);
}
