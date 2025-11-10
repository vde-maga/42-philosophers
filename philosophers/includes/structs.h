/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:25:45 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 14:46:07 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stats
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	pthread_mutex_t	monitoring_mutex;
	int				simulation_should_end;
}					t_stats;

typedef struct s_philo
{
	int				philo_nbr;
	int				eaten_meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	suseconds_t		last_meal_time;
	pthread_t		t_id;
	suseconds_t		start_time;
	t_stats			*stats;
}					t_philo;

#endif
