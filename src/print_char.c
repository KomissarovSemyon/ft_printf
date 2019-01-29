/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 06:27:14 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/29 06:46:16 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(char c, t_token *tok)
{
	int		i;
	int		w;

	w = tok->width;
	i = 1;
	if (w < 2)
		return (ft_putchar(c));
	if ((tok->flags & F_MINUS) == F_MINUS)
	{
		ft_putchar(c);
		while (i < w)
			i += ft_putchar(' ');
	}
	else
	{
		while (i < w)
			i += ft_putchar(' ');
		ft_putchar(c);
	}
	return (i);
}