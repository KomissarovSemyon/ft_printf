/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:00:02 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/30 17:56:42 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long int n, t_token *tok)
{
	(void)tok;
	int		i;
	int		res;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	str = ft_strnew(14);
	str[0] = '0';
	str[1] = 'x';
	i = 13;
	while (i > 1)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	res = print_string(str, tok);
	free(str);
	return (res);
}
