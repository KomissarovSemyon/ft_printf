/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 03:16:27 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/12 22:59:12 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_frac_from_bin(char *s)
{
	char	*res;
	char	*now;
	int		i;

	now = ft_strdup(".0");
	res = ft_strdup(".0");
	i = 0;
	while (s[++i])
	{
		now = str_div2(&now);
		if (s[i] == '1')
			res = str_add_fraction(&res, now);
	}
	free(now);
	return (res);
}

char	*get_int_from_bin(char *s)
{
	char	*res;
	char	*now;
	char	*tmp;
	int		i;

	i = ft_strlen(s);
	now = ft_strdup("1");
	res = ft_strdup("0");
	while (--i >= 0)
	{
		if (s[i] == '1')
			res = str_add_int(&res, now, 1);
		tmp = str_add_int(&now, now, 0);
		free(now);
		now = tmp;
	}
	free(now);
	return (res);
}
