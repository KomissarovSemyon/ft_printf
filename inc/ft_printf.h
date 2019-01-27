/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:11:07 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 10:18:04 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

enum	e_flag
{
	CHAR,
	POINTER,
	STRING
};

typedef	struct	s_token
{
	enum e_flag	flag;
	int			width;
	int			precision;
}				t_token;


int		ft_printf(const char *f, ...);

#endif
