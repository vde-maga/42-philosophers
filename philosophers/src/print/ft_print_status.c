/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:35:17 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/18 15:53:43 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, t_state state)
{
	long long	time;

	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->someone_died)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		time = ft_time_diff(philo->table->start_time, ft_time_get_time());
		if (state == FORK_TAKEN)
			printf(BOLD "%4lld " CYAN "%2i " GREEN "%16s \033[0m\n", time,
				philo->id, "has taken a fork");
		else if (state == EATING)
			printf(BOLD "%4lld " CYAN "%2i " YELLOW "%16s \033[0m\n" RESET,
				time, philo->id, "is eating");
		else if (state == SLEEPING)
			printf(BOLD "%4lld " CYAN "%2i " BLUE "%16s \033[0m\n" RESET, time,
				philo->id, "is sleeping");
		else if (state == THINKING)
			printf(BOLD "%4lld " CYAN "%2i " PURPLE "%16s \033[0m\n" RESET,
				time, philo->id, "is thinking");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
}
