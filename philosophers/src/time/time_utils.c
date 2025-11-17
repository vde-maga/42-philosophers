/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:09:56 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/14 14:46:02 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_error(NULL, "gettimeofday() failed"));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_time_precise_sleep(long long time)
{
	long long	start;

	start = ft_time_get_time();
	while ((ft_time_get_time() - start) < time)
		usleep(50);
}

long long	ft_time_diff(long long past, long long present)
{
	return (present - past);
}
