/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:09:26 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/31 12:28:44 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *f, ...)
{
	int		i;
	int		k;
	int		res;
	va_list	ap;

	i = -1;
	res = 0;
	k = 0;
	va_start(ap, f);
	while (f[++i])
	{
		if (f[i] == '%')
			res += process_token(f + i + 1, &i, ap);
		else
		{
			k = ft_putstr_until((char *)f + i, '%') - 1;
			res += k;
			i += k;
		}
	}
	va_end(ap);
	return (res);
}
