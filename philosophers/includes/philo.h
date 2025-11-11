/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:57:19 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/11 15:19:41 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define DEAD_MSG "is dead \n"
# define EAT_MSG "is eating \n"
# define THINK_MSG "is thinking \n"
# define SLEEP_MSG "is sleeping \n"
# define FORK_MSG "has taken a fork \n"
# define DROP_MSG "has dropped a fork \n"

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
# include "libft.h"
# include "structs.h"
# include "colors.h"

// -----------------------------------------------------------------------------
// ---------------------- Prototypes -------------------------------------------
// -----------------------------------------------------------------------------

// ---------------------- Parsing ----------------------------------------------
int				ft_arguments_check(int argc, char **argv);

// ---------------------- Error ------------------------------------------------
int				ft_error(t_stats *stats, pthread_mutex_t *forks,
					t_philo *philos, char *error);
void			ft_free(t_stats *stats, pthread_mutex_t *forks, t_philo *philo);

// ---------------------- Init -------------------------------------------------
int				ft_init_stats(t_stats *stats, char **argv);
pthread_mutex_t	*ft_init_forks(t_stats *stats);
t_philo			*ft_init_philos(t_stats *stats, pthread_mutex_t *forks);
suseconds_t		ft_get_time(void);

// ---------------------- Simulation -------------------------------------------
int				ft_run_simulation(t_stats *stats, t_philo *philos,
					pthread_mutex_t *forks);

// ---------------------- Monitoring -------------------------------------------
void			ft_monitor_simulation(t_philo *philos, t_stats *stats);

// ---------------------- Philo ------------------------------------------------
void			*ft_philos_routine(void *_philo);
void			ft_philo_monitoring(t_philo *philo, t_event_id event_id);
void			ft_philo_eat(t_philo *philo);
void			ft_philo_sleep(t_philo *philo);
#endif
