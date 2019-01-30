/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:00:02 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/30 18:35:31 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long int n, t_token *tok)
{
	int		i;
	int		res;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	res = ft_nbrlen_base(n, 16) + 1;
	str = ft_strnew(res + 2);
	str[0] = '0';
	str[1] = 'x';
	i = res;
	while (i > 1)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	res = print_string(str, tok);
	ft_strdel(&str);
	return (res);
}
