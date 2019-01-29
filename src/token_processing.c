/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 10:22:52 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/29 05:59:48 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
*	эта функция должна парсить строку и получать токен с шириной, точностью
*	и доп флагами
*/

void	get_spec(const char *f, t_token *tok)
{
	int i;

	i = 0;
	if (f[i] == S_CHAR)
		tok->spec = S_CHAR;
	else if (f[i] == S_STRING)
		tok->spec = S_STRING;
	else if (f[i] == S_POINTER)
		tok->spec = S_POINTER;
}

int		begin_flag(char c)
{
	if (c == '-')
		return (F_MINUS);
	if (c == '0')
		return (F_ZERO);
	if (c == '+')
		return (F_PLUS);
	if (c == '#')
		return (F_SHARP);
	if (c == ' ')
		return (F_SPACE);
	return (0);
}

int		length_flag(const char *f, int *i)
{
	if ((f[*i] == 'h' && f[*i + 1] == 'h') ||
		(f[*i] == 'l' && f[*i + 1] == 'l'))
	{
		*i += 2;
		return (f[*i - 1] == 'h' ? F_HH : F_LL);
	}
	else if (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z')
	{
		*i += 1;
		if (f[*i - 1] == 'h')
			return (F_H);
		if (f[*i - 1] == 'l')
			return (F_L);
		if (f[*i - 1] == 'j')
			return (F_J);
		if (f[*i - 1] == 'z')
			return (F_Z);
	}
	return (0);
}

int		parse_token(const char *f, t_token *tok)
{
	int	i;
	int	flag;

	i = 0;
	while ((flag = begin_flag(f[i])))
	{
		tok->flags = tok->flags | flag;
		i++;
	}
	while (ft_isdigit(f[i]))
	{
		tok->width = tok->width * 10 + f[i] - '0';
		i++;
	}
	if (f[i] == '.')
		while (ft_isdigit(f[++i]))
			tok->precision == -1 ? (tok->precision = f[i] - '0') :
				(tok->precision = tok->precision * 10 + f[i] - '0');
	if ((flag = length_flag(f, &i)))
		tok->flags = tok->flags | flag;
	tok->spec = f[i];
	return (i);
}

int		process_token(const char *f, int *i, va_list ap)
{
	t_token	tok;

	tok.width = 0;
	tok.precision = -1;
	*i += parse_token(f, &tok);
	printf("|%c - %d - %d - %d|", tok.spec, tok.width, tok.precision, tok.flags);
	if (tok.spec == S_CHAR)
		return (ft_putchar(va_arg(ap, int)));
	else if (tok.spec == S_STRING)
		return (ft_putstr(va_arg(ap, char *)));
	else if (tok.spec == S_POINTER)
		return (ft_putstr("pointer kek!"));
	return (0);
}

int		skip_token(const char *f)
{
	(void)f;
	return (1);
}