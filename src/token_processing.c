/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 10:22:52 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 13:14:13 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
*	эта функция должна парсить строку и получать токен с шириной, точностью
*	и доп флагами
*/

void	get_token(const char *f, t_token *tok)
{
	int i;

	i = 0;
	if (f[i] == CHAR)
		tok->spec = CHAR;
	else if (f[i] == STRING)
		tok->spec = STRING;
	else if (f[i] == POINTER)
		tok->spec = POINTER;
}

int		process_token(const char *f, va_list ap)
{
	t_token	tok;

	get_token(f, &tok);
	if (tok.spec == CHAR)
		return (ft_putchar(va_arg(ap, int)));
	else if (tok.spec == STRING)
		return (ft_putstr(va_arg(ap, char *)));
	else if (tok.spec == POINTER)
		return (ft_putstr("pointer kek!"));
	return (0);
}

int		skip_token(const char *f)
{
	(void)f;
	return (1);
}