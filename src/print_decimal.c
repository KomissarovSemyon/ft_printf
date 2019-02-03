/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 22:10:07 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/03 13:21:58 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(long long int n, t_token *tok)
{
	char	*str;

	if ((tok->flags & F_HH) == F_HH)
		str = ft_ltoa_base((char)n, 10);
	else if ((tok->flags & F_H) == F_H)
		str = ft_ltoa_base((short)n, 10);
	else if ((tok->flags & F_L) == F_L)
		str = ft_ltoa_base((long)n, 10);
	else if ((tok->flags & F_LL) == F_LL)
		str = ft_ltoa_base((long long)n, 10);
	else if ((tok->flags & F_J) == F_J)
		str = ft_ltoa_base((intmax_t)n, 10);
	else if ((tok->flags & F_Z) == F_Z)
		str = ft_ltoa_base((size_t)n, 10);
	else
		str = ft_ltoa_base((int)n, 10);
	// return (ft_putstr(str));
	return (print_number(str, tok, str[0] != '-'));
}
