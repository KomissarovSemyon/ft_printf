/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arth2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 03:16:27 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/10 10:08:53 by amerlon-         ###   ########.fr       */
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

static char	*dbl_transform_if(t_double *d)
{
	char	*res;

	if (!(res = ft_nchjoinstr(d->mantissa, '0', -(d->exponent))))
		return (NULL);
	res[1] = '.';
	res[-(d->exponent) + 1] = '1';
	res[-(d->exponent)] = '0';
	free(d->mantissa);
	d->mantissa = res;
	return (res);
}

char		*dbl_transform(t_double *d)
{
	int		l;
	char	*res;

	if (d->sign == 0 && d->exponent == -1023 && !ft_strcmp(d->mantissa, "1."))
	{
		free(d->mantissa);
		d->mantissa = ft_strdup("0.0");
	}
	else if (d->exponent < 0)
		dbl_transform_if(d);
	else if (d->exponent > 0)
	{
		if (!(res = ft_strjoinnch(d->mantissa, '0',
			ft_strlen(d->mantissa) - 3 - d->exponent)))
			return (NULL);
		free(d->mantissa);
		d->mantissa = res;
		l = 1;
		while ((d->exponent)-- > 0)
		{
			res[l] = res[l + 1];
			res[l++ + 1] = '.';
		}
	}
	return (d->mantissa);
}

char		*dbl_to_str(double d)
{
	char		*res;
	char		*frac;
	char		*inte;
	t_double	*dbl;

	dbl = get_double(d);
	dbl_transform(dbl);
	inte = ft_copyuntil(dbl->mantissa, '.');
	frac = ft_strchr(dbl->mantissa, '.');
	res = get_int_from_bin(inte);
	free(inte);
	inte = res;
	res = get_frac_from_bin(frac);
	frac = res;
	res = ft_strjoin(inte, frac);
	free(inte);
	free(frac);
	free(dbl->mantissa);
	free(dbl);
	return (res);
}
