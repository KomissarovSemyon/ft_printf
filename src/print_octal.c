/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:10:23 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/04 01:05:51 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_octal(unsigned int n, t_token *tok)
{
	char	*str;
	char	*temp;
	int		res;

	tok->flags = tok->flags & (~F_PLUS);
	if (!(str = ft_ltoa_base(n, 8)))
		return (0);
	if ((tok->flags & F_SHARP) == F_SHARP)
	{
		if (tok->precision == 0 && n == 0)
		{
			tok->precision = -1;
			res = print_number("0", tok, 1);
		}
		else
		{
			temp = ft_chjoinstr('0', str);
			res = print_number(temp, tok, 1);
			free(temp);
		}
	}
	else
		res = print_number(str, tok, 1);
	free(str);
	return (res);
}
