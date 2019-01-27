/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:11:07 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/27 13:13:50 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

/*
*	макросы для заменения аски значения спецификатора
*/

# define CHAR 'c'
# define STRING 's'
# define POINTER 'p'

/*
*	основная структура хранения токенов
*	width		-	ширина
*	precision	-	точность
*	flags		-	дополнительные флаги:
*		none	print normally (right justify, space fill)	0
*		-		left justify								2^0
*		0		leading zero fill							2^1
*		+		print plus on positive numbers				2^2
*		#		multi use									2^3
*		space	invisible plus sign							2^4
*	за каждый флаг отвичает свой бит, например если считали с флагами
* 	- и +, то значени flags=5
*/

typedef	struct		s_token
{
	unsigned char	spec;
	unsigned char	width;
	unsigned char	precision;
	int				flags;
}					t_token;

int		ft_printf(const char *f, ...);
void	get_token(const char *f, t_token *tok);
int		process_token(const char *tok, va_list ap);
int		skip_token(const char *f);

#endif
