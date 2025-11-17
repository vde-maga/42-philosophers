/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:47:29 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/13 16:51:16 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing_check_time_values(char **argv)
{
	if (ft_atoi(argv[2]) < 61)
	{
		ft_error(NULL, "Die Time must be greater than 60 ms");
		return (1);
	}
	if (ft_atoi(argv[3]) < 61)
	{
		ft_error(NULL, "Eat Time must be greater than 60 ms");
		return (1);
	}
	if (ft_atoi(argv[4]) < 61)
	{
		ft_error(NULL, "Sleep Time must be greater than 60 ms");
		return (1);
	}
	return (0);
}

int	ft_parsing_check_philo_number(char *argv)
{
	if (ft_atoi(argv) <= 0)
	{
		ft_error(NULL, "Need at least 1 Philosopher");
		return (1);
	}
	if (ft_atoi(argv) > 200)
	{
		ft_error(NULL, "Too Many Philosophers (Max 200)");
		return (1);
	}
	return (0);
}

int	ft_parsing_is_valid_number(char *argv)
{
	int	i;

	if (!argv || !argv[0])
		return (1);
	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_parsing_check_limits(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(&argv[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}
