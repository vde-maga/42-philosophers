/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:42:28 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 16:20:43 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_stats			stats;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (ft_arguments_check(argc, argv) == 1)
		return (EXIT_FAILURE);
	if (ft_init_stats(&stats, argv) == 1)
		return (EXIT_FAILURE);
	forks = ft_init_forks(&stats);
	philos = ft_init_philos(&stats, forks);
	if (ft_run_simulation(&stats, philos, forks) == 1)
		return (EXIT_FAILURE);
	ft_free(&stats, forks, philos);
	return (EXIT_SUCCESS);
}
