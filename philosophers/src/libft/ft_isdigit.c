/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:23:30 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 12:22:07 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	printf("Teste 1 (a): %d\n", ft_isdigit('a'));
	printf("Teste 1 (z): %d\n", ft_isdigit('z'));

	printf("Teste 2 (A): %d\n", ft_isdigit('A'));
	printf("Teste 2 (Z): %d\n", ft_isdigit('Z'));

	printf("Teste 3 (0): %d\n", ft_isdigit('0'));
	printf("Teste 3 (!): %d\n", ft_isdigit('!'));
	printf("Teste 3 ( ): %d\n", ft_isdigit(' '));
}
*/
