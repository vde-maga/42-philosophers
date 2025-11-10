/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:49:56 by vde-maga          #+#    #+#             */
/*   Updated: 2025/11/10 11:10:30 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	size_t	len4;

	// Teste 1: String vazia
	len1 = ft_strlen("");
	if (len1 == 0)
	{
		printf("Teste 1 (String vazia): Passado\n");
	}
	else
	{
		printf("Teste 1 (String vazia): Falhou, esperado: 0, obtido: %zu\n",
			len1);
	}
	// Teste 2: String com um caractere
	len2 = ft_strlen("a");
	if (len2 == 1)
	{
		printf("Teste 2 (Um caractere): Passado\n");
	}
	else
	{
		printf("Teste 2 (Um caractere): Falhou, esperado: 1, obtido: %zu\n",
			len2);
	}
	// Teste 3: String com múltiplos caracteres
	len3 = ft_strlen("hello");
	if (len3 == 5)
	{
		printf("Teste 3 (Multiplos caracteres): Passado\n");
	}
	else
	{
		printf("Teste 3 (Multiplos caracteres): Falhou, esperado: 5, obtido:
			%zu\n", len3);
	}
	// Teste 4: String com espaços
	len4 = ft_strlen("hello world");
	if (len4 == 11)
	{
		printf("Teste 4 (Espaços): Passado\n");
	}
	else
	{
		printf("Teste 4 (Espaços): Falhou, esperado: 11, obtido: %zu\n", len4);
	}
	return (0);
}
*/
