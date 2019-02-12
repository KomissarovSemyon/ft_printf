/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semyonkomissarov <semyonkomissarov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 03:37:36 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/12 08:27:42 by semyonkomis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*round_dbl(char **s, int p)
{
	int	i;
	int prev;
	// char	*tmp;

	i = ft_strchr(*s, '.') - *s + p + 1;
	prev = (*s)[i] >= '5' ? 1 : 0;
	(*s)[i] = '\0';
	while (--i != 0)
	{
		if ((*s)[i] == '.')
			continue ;
		(*s)[i] += (*s)[i + 1] >= '5' ? 1 : 0 + prev;
		if ((prev = (*s)[i] > '9'))
			(*s)[i] -= 10;
		if (!prev)
			break ;
	}
	return (*s);
}

int	print_double(long double n, t_token *tok)
{
	n = 0;
	(void)tok;
	return (0);
}
