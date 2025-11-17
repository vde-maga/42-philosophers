/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:55:30 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/13 15:52:35 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_table *table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	if (table->forks)
	{
		while (i < table->num_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->last_meal_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	if (table->philosophers)
		free(table->philosophers);
}

int	ft_error(t_table *table, char *error)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	ft_free(table);
	return (EXIT_FAILURE);
}
