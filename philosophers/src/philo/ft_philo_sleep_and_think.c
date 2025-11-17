/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep_and_think.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:39:57 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/14 15:40:54 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_sleep_and_think(t_philo *philo)
{
	ft_print_status(philo, SLEEPING);
	ft_time_precise_sleep(philo->table->time_to_sleep);
	ft_print_status(philo, THINKING);
	return (0);
}
