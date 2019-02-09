/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:02:26 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/09 04:31:34 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_add_fraction(char **s1, char *s2)
{
	int		l1;
	int		l2;
	int		prev;
	char	*res;

	if (!s1 || !s2 || !*s1)
		return (NULL);
	l1 = ft_strlen(*s1);
	l2 = ft_strlen(s2);
	if (!(res = ft_strdup(l1 > l2 ? *s1 : s2)))
		return (NULL);
	l1 = l1 > l2 ? l2 : l1;
	prev = 0;
	while (res[--l1] != '.')
	{
		res[l1] = (*s1)[l1] + s2[l1] - '0' + prev;
		if ((prev = res[l1] > '9'))
			res[l1] -= 10;
	}
	ft_strdel(s1);
	return (res);
}

char	*str_add_int(char **s1, char **s2)
{
	int		l1;
	int		l2;
	int		i;
	int		prev;
	char	*res;

	l1 = ft_strlen(*s1);
	l2 = ft_strlen(*s2);
	i = l1 > l2 ? l1 : l2 + 1;
	res = ft_strnew(i);
	prev = 0;
	while (--i >= 0)
	{
		res[i] = ((--l1 >= 0) ? (*s1)[l1] : '0') +
			((--l2 >= 0) ? (*s2)[l2] : '0') - '0' + prev;
		if ((prev = res[i] > '9'))
			res[i] -= 10;
	}
	if (prev && res[0] == 0)
		res[0] = '1';
	else if (res[0] == 0 || res[0] == '0')
		res = ft_strshift(&res, 1);
	ft_strdel(s1);
	ft_strdel(s2);
	return (res);
}

char	*str_div2(char **str)
{
	char	*res;
	char	now;
	int		i;

	if (ft_strcmp(".0", *str) == 0)
		return (ft_strdup(".5"));
	if (!(res = ft_strjoinch(str, '0')))
		return (NULL);
	i = ft_strlen(res) - 1;
	while (--i >= 0)
	{
		now = res[i];
		if (now == '1' || now == '3' || now == '5' || now == '7' || now == '9')
		{
			now--;
			res[i + 1] += 5;
		}
		if (now == '.')
			break ;
		if (now != '0')
			now = (now - '0') / 2 + '0';
		res[i] = now;
	}
	*str = res;
	return (res);
}

t_double	*get_double(double d)
{
	unsigned long	*n = (unsigned long *)&d;
	int				i;
	t_double		*res;


	if (!(res = (t_double *)malloc(sizeof(t_double))))
		return (NULL);
	i = 62;
	res->sign = d > 0;
	res->exponent = ((*n) << 1) >> 53;
	res->mantissa = (*n) << 12;
	return (res);
}