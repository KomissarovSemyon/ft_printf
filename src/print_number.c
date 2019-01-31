/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:39:33 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/31 20:27:44 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_positive(char *str, t_token *tok)
{
	char	sign;
	char	*str_new;
	int		res;

	sign = '\0';
	res = 0;
	if ((tok->flags & F_SPACE) == F_SPACE)
		sign = ' ';
	if ((tok->flags & F_PLUS) == F_PLUS)
		sign = '+';
	if (((tok->flags & F_ZERO) == F_ZERO) &&
		((tok->flags & F_MINUS) != F_MINUS))
	{
		sign != '\0' ? res += ft_putchar(sign) : (0);
		res += print_no_flag(str, tok->width - (sign != '\0'), -1, '0');
	}
	else
	{
		str_new = ft_chjoinstr(sign, str);
		res += ((tok->flags & F_MINUS) == F_MINUS) ?
			print_with_flag(str_new, tok->width, -1, ' ') :
			print_no_flag(str_new, tok->width, -1, ' ');
		free(str_new);
	}
	return (res);
}

static int	print_negative(char *str, t_token *tok)
{
	int		res;

	res = 0;
	if (((tok->flags & F_ZERO) == F_ZERO) &&
		((tok->flags & F_MINUS) != F_MINUS))
	{
		res += ft_putchar('-');
		res += print_no_flag(str + 1, tok->width - 1, -1, '0');
	}
	else
	{
		res += ((tok->flags & F_MINUS) == F_MINUS) ?
			print_with_flag(str, tok->width, -1, ' ') :
			print_no_flag(str, tok->width, -1, ' ');
	}
	return (res);
}

int		print_number(char *str, t_token *tok, int sign)
{
	if (sign)
		return (print_positive(str, tok));
	return (print_negative(str, tok));
}
