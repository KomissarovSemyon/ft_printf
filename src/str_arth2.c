/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arth2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 03:16:27 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/09 06:37:08 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_mantissa_string(unsigned long m)
{
	char	*res;
	char	*now;
	int		i;

	i = 0;
	now = ft_strdup(".0");
	res = ft_strdup(".0");
	while ((m << i) > 0)
	{
		now = str_div2(&now);
		if (((m >> (63 - i)) & 1) == 1)
		{
			if (!(res = str_add_fraction(&res, now)))
			{
				free(now);
				free(res);
				return (NULL);
			}
		}
		i++;
	}
	return (res);
}
