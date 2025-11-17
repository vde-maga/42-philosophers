/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:48:26 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/14 15:34:05 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *philosopher_void)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher_void;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (ft_monitor_philo_check_someone_died(philo->table) != 1)
	{
		if (ft_philo_take_forks(philo) != 0)
			break ;
		if (ft_philo_eat(philo) != 0)
			break ;
		if (ft_philo_sleep_and_think(philo) != 0)
			break ;
		usleep(200);
	}
	return (NULL);
}
