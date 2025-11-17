/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:35:37 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/14 15:37:47 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eat(t_philo *philo)
{
	ft_print_status(philo, EATING);
	pthread_mutex_lock(&philo->table->last_meal_mutex);
	philo->last_meal = ft_time_get_time();
	pthread_mutex_unlock(&philo->table->last_meal_mutex);
	philo->meals_eaten++;
	ft_time_precise_sleep(philo->table->time_to_eat);
	ft_philo_drop_forks(philo);
	return (0);
}
