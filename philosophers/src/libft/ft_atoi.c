/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:59:52 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 11:18:55 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	result;
	int	signal;

	result = 0;
	signal = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal = signal * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * signal);
}
/*
int	main(void)
{
	const char	*test_cases[] =
	{
		"42",
		"-42",
		"2147483647",
		"-2147483648",
		"  +12345",
		"  -12345",
		"123abc",
		"abc123",
		"",
		"     ",
		"9223372036854775807",
		"-9223372036854775808"
	};
	int	i = 0;
	while (i < (int)(sizeof(test_cases) / sizeof(test_cases[0])))
	{
		const char	*str = test_cases[i];
		int	result = ft_atoi(str);
		printf("Entrada: \"%s\" => Saída: %d\n", str, result);
		i++;
	}
	return (0);
}
*/
