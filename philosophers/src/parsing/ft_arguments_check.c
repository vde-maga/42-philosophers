/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+ m>     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:53:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/13 17:02:41 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_arguments_check(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (ft_error(NULL, "Invalid Number of Arguments"), 1);
	i = 1;
	while (i < argc)
	{
		if (ft_parsing_is_valid_number(argv[i]) == 1)
			return (ft_error(NULL, "Invalid Argument Format"), 1);
		if (ft_parsing_check_limits(argv[i]) == 1)
			return (ft_error(NULL, "Argument Too Large"), 1);
		i++;
	}
	if (ft_parsing_check_philo_number(argv[1]) == 1)
		return (1);
	if (ft_parsing_check_time_values(argv) == 1)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (ft_error(NULL, "Meals Number Must Be Positive"), 1);
	return (0);
}
