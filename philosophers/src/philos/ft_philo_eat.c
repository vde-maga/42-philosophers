/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:21:15 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/11 13:44:16 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_pick_forks(t_philo *philo)
{
	if (philo->philo_nbr % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		ft_philo_monitoring(philo, FORK);
		pthread_mutex_unlock(philo->right_fork);
		ft_philo_monitoring(philo, FORK);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		ft_philo_monitoring(philo, FORK);
		pthread_mutex_unlock(philo->left_fork);
		ft_philo_monitoring(philo, FORK);
	}
}

void	ft_philo_drop_forks(t_philo *philo)
{
	if (philo->philo_nbr % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		ft_philo_monitoring(philo, DROP);
		pthread_mutex_unlock(philo->right_fork);
		ft_philo_monitoring(philo, DROP);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		ft_philo_monitoring(philo, DROP);
		pthread_mutex_unlock(philo->left_fork);
		ft_philo_monitoring(philo, DROP);
	}
}

void	ft_philo_eat(t_philo *philo)
{
	ft_philo_pick_forks(philo);
	pthread_mutex_lock(&philo->stats->monitoring_mutex);
	philo->last_meal_time = ft_get_time();
	philo->eaten_meals = philo->eaten_meals + 1;
	pthread_mutex_unlock(&philo->stats->monitoring_mutex);
	ft_philo_monitoring(philo, EAT);
	usleep(philo->stats->time_to_eat * 1000);
	ft_philo_drop_forks(philo);
}
