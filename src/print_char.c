/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semyonkomissarov <semyonkomissarov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 06:27:14 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/13 18:12:07 by semyonkomis      ###   ########.fr       */
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
			i += ft_putchar((tok->flags & F_ZERO) == F_ZERO ? '0' : ' ');
	}
	else
	{
		while (i < w)
			i += ft_putchar((tok->flags & F_ZERO) == F_ZERO ? '0' : ' ');
		ft_putchar(c);
	}
	return (i);
}
