/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:09:26 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 09:46:57 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *f, ...)
{
	int	i;

	i = -1;
	while (f[++i])
	{
		// if (f[i] == '%')
		// 	get_flag()
		ft_putchar(f[i]);
	}
	return (i);
}
