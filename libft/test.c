/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:42:19 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/30 18:30:17 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("%d\n", ft_nbrlen_base(atol(argv[1]), atoi(argv[2])));
	printf("%lld", (unsigned long long int)argv);
	return (0);
}