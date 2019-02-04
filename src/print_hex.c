/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 02:10:49 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/04 03:47:18 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ltoa_sizet_hex(size_t n)
{
	char			*hex;
	int				i;
	int				l;
	char			*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	hex = "0123456789abcdef";
	l = ft_nbrlen_base(n, 16);
	res = ft_strnew(l);
	while (n)
	{
		res[--l] = hex[n % 16];
		n /= 16;
	}
	return (res);
}

static size_t	cast_to_flag(size_t n, t_token *tok)
{
	if ((tok->flags & F_HH) == F_HH)
		return ((unsigned char)n);
	else if ((tok->flags & F_H) == F_H)
		return ((unsigned short)n);
	else if ((tok->flags & F_L) == F_L)
		return ((unsigned long)n);
	else if ((tok->flags & F_LL) == F_LL)
		return ((unsigned long long)n);
	else if ((tok->flags & F_J) == F_J)
		return ((intmax_t)n);
	else if ((tok->flags & F_Z) == F_Z)
		return ((size_t)n);
	return ((unsigned int)n);
}

int	print_hex(size_t n, t_token *tok)
{
	char	*str;
	char	*temp;
	int		res;

	tok->flags = tok->flags & (~F_PLUS);
	if (!(str = ft_ltoa_sizet_hex(cast_to_flag(n, tok))))
		return (0);
	if ((tok->flags & F_SHARP) == F_SHARP)
	{
		if (n == 0)
			res = print_number("0", tok, 1);
		else
		{
			temp = ft_strjoin("0x", str);
			res = print_number(temp, tok, 1);
			free(temp);
		}
	}
	else
		res = print_number(str, tok, 1);
	free(str);
	return (res);
}
