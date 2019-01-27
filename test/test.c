/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 05:03:36 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 06:53:41 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf(" -%d\n", printf("%s", "sadsd"));
	printf(" -%d\n", printf("%s", "sadsd"));
	printf(" -%d\n", printf("%s", "s"));
	printf(" -%d\n", printf("%s", ""));
	// printf(" -%d\n", printf("%s", NULL));
	return (0);
}
