/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 05:03:36 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 13:09:04 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
*	Пишем тесты только в test.c
*	правило test в Makefile само создаст файл с такими же тестами,
*	заменив каждый второй printf в строчке на ft_printf
*/

int	main(void)
{
	/*
	**	NO PARAMETERS, NO FLAGS
	*/
	printf(" -%d\n", printf("aausbdi"));
	printf(" -%d\n", printf(""));

	/*
	**	BASIC STRINGS
	*/
	printf(" -%d\n", printf("%s", "sadsd"));
	printf(" -%d\n", printf("%s", "s"));
	// printf(" -%d\n", printf("%s", NULL));
	// printf(" -%d\n", printf("%s", ""));
	return (0);
}
