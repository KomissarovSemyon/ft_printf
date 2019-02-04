/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsignedl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 02:16:41 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/05 02:21:16 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ltoa_sizet(size_t n)
{
	int		i;
	int		l;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	l = ft_nbrlen_base(n, 10);
	res = ft_strnew(l);
	while (n)
	{
		res[--l] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

int			print_unsignedl(unsigned long long int n, t_token *tok)
{
	char	*str;
	int		res;

	tok->flags = tok->flags & (~F_SPACE);
	tok->flags = tok->flags & (~F_PLUS);
	str = ft_ltoa_sizet((unsigned long)n);
	if (!str)
		return (0);
	res = print_number(str, tok, 1);
	free(str);
	return (res);
}
