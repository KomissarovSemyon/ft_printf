/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:11:07 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 11:00:02 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

/*
*	Список всех подерживаемых спецификаторов
*/

enum	e_spec
{
	CHAR,
	POINTER,
	STRING
};

/*
*	основная структура хранения токенов
*	width		-	ширина
*	precision	-	точность
*	flags		-	дополнительные флаги:
*		none	print normally (right justify, space fill)	0
*		-		left justify								2^0
*		0		leading zero fill							2^1
*		+		print plus on positive numbers				2^2
*		space	invisible plus sign							2^3
*	за каждый флаг отвичает свой бит, например если считали с флагами
* 	- и +, то значени flags=5
*/

typedef	struct	s_token
{
	enum e_spec	spec;
	int			width;
	int			precision;
	int			flags;
}				t_token;


int		ft_printf(const char *f, ...);
void	get_token(const char *f, t_token *tok);


#endif
