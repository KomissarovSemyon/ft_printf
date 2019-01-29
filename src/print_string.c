/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:54:44 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/29 08:59:21 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_flag(char *str, int w, int p)
{
	int		i;

	i = 0;
	if (p == -1)
	{
		i += ft_putstr(str);
		while (i < w)
			i += ft_putchar(' ');
	}
	else
	{
		while (i < p && str[i])
			ft_putchar(str[i++]);
		while (i < w)
			i += ft_putchar(' ');
	}
	return (i);
}

static int	print_no_flag(char *str, int w, int p)
{
	int		i;
	int		j;
	int		l;
	int		len;

	len = ft_strlen(str);
	l = (p == -1) ? len : p;
	if (p != -1)
		l = (len > p) ? p : len;
	i = 0;
	while (w - i > l)
		i += ft_putchar(' ');
	j = -1;
	while (str[++j] && j < l)
		i += ft_putchar(str[j]);
	return (i);
}

int		print_string(char *s, t_token *tok)
{
	int	i;
	int	w;
	int	p;

	w = tok->width;
	p = tok->precision;
	if (!s)
		return (((tok->flags & F_MINUS) != F_MINUS) ? 
			print_no_flag("(null)", w, p) : print_with_flag("(null)", w, p));
	i = 0;
	if ((tok->flags & F_MINUS) != F_MINUS)
		return(print_no_flag(s, w, p));
	else
		return(print_with_flag(s, w, p));
}
