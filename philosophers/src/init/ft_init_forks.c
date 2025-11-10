/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:57:08 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 15:11:36 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_forks_until(pthread_mutex_t *forks, int until)
{
	int	i;

	i = 0;
	while (i <= until)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

pthread_mutex_t	*ft_init_forks(t_stats *stats)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(stats->nbr_of_philo * sizeof(pthread_mutex_t));
	if (!forks)
		ft_error(stats, NULL, NULL, "Error: Memory Alocation of Forks Failed");
	i = 0;
	while (i < stats->nbr_of_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_free_forks_until(forks, i);
			ft_error(stats, NULL, NULL,
				"Error: Failed to Initialize Mutex of Forks");
		}
		i++;
	}
	return (forks);
}
