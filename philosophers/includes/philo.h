/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:57:19 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/17 10:44:48 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// -----------------------------------------------------------------------------
// ---------------------- Librarys ---------------------------------------------
// -----------------------------------------------------------------------------

// External
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
// My Librarys
# include "colors.h"
# include "libft.h"
# include "structs.h"

// -----------------------------------------------------------------------------
// ---------------------- Prototypes -------------------------------------------
// -----------------------------------------------------------------------------

// Parsing
int			ft_arguments_check(int argc, char **argv);
int			ft_parsing_is_valid_number(char *argv);
int			ft_parsing_check_limits(char *argv);
int			ft_parsing_check_philo_number(char *argv);
int			ft_parsing_check_time_values(char **argv);

// Init
int			ft_init_table(t_table *table, int argc, char **argv);

// Error
int			ft_error(t_table *table, char *error);
void		ft_free(t_table *table);

// Time
long long	ft_time_get_time(void);
void		ft_time_precise_sleep(long long time);
long long	ft_time_diff(long long past, long long preset);

// Philo
void		*ft_philo_routine(void *philosopher_void);
int			ft_philo_eat(t_philo *philo);
int			ft_philo_take_forks(t_philo *philo);
int			ft_philo_sleep_and_think(t_philo *philo);
void		ft_philo_drop_forks(t_philo *philo);
int			ft_monitor_philo_check_someone_died(t_table *table);
int			ft_monitor_check_philosopher_is_death(t_table *table, int i);

// Simulation
int			ft_simulation_handle_one_philo(t_table *table);
int			ft_simulation_start_simulation(t_table *table);

// Monitor
void		*ft_monitor_routine(void *table_void);
int			ft_monitor_philo_all_ate_enought(t_table *table);

// Printf
void		ft_print_status(t_philo *philo, t_state state);
#endif
