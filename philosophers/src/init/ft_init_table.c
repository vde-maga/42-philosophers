/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:59:00 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/17 12:17:52 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_parse_args(t_table *table, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ft_error(NULL, "Invalid number of arguments."));
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	if (table->num_philos <= 0 || table->num_philos > 200
		|| table->time_to_die <= 0 || table->time_to_eat <= 0
		|| table->time_to_sleep <= 0 || (argc == 6 && table->must_eat <= 0))
		return (ft_error(NULL, "Invalid argument value."));
	return (0);
}

int	ft_init_parse_allocate_memory(t_table *table)
{
	table->someone_died = 0;
	table->philosophers = NULL;
	table->forks = NULL;
	table->start_time = ft_time_get_time();
	if (table->start_time < 0)
		return (ft_error(NULL, "Failed to get start time."));
	table->philosophers = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philosophers)
		return (ft_error(table, "Malloc failed for philosophers."));
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (ft_error(table, "Malloc failed for forks."));
	return (0);
}

int	ft_init_mutexes(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			return (ft_error(table, "Fork mutex initialization failed."));
		}
	}
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (ft_error(table, "Print mutex initialization failed."));
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
		return (ft_error(table, "Death mutex initialization failed."));
	if (pthread_mutex_init(&table->last_meal_mutex, NULL) != 0)
		return (ft_error(table, "Last meal mutex initialization failed."));
	return (0);
}

void	ft_init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philosophers[i].id = i + 1;
		table->philosophers[i].meals_eaten = 0;
		table->philosophers[i].last_meal = table->start_time;
		table->philosophers[i].state = THINKING;
		table->philosophers[i].table = table;
		table->philosophers[i].left_fork = &table->forks[i];
		table->philosophers[i].right_fork = &table->forks[(i + 1)
			% table->num_philos];
		i++;
	}
}

int	ft_init_table(t_table *table, int argc, char **argv)
{
	if (ft_init_parse_args(table, argc, argv) != 0)
		return (1);
	if (ft_init_parse_allocate_memory(table) != 0)
		return (1);
	if (ft_init_mutexes(table) != 0)
		return (1);
	ft_init_philosophers(table);
	return (0);
}
