/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+ m>     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:53:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/11 15:31:38 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_all_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_arguments_check(int argc, char **argv)
{
	if ((argc != 5 && argc != 6) || ft_is_all_numbers(argv) == 1)
	{
		ft_error(NULL, NULL, NULL, "Error: Invalid Number of Arguments");
		return (1);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		ft_error(NULL, NULL, NULL,
				"Error: Please dont use more than 200 Philosophers");
		return (1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		ft_error(NULL, NULL, NULL,
				"Error: Time specified less than 60ms");
		return (1);
	}
	return (0);
}
