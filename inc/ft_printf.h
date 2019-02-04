/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:11:07 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/04 03:18:05 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

# include <stdio.h> // DELETE THIS

/*
**	макросы для заменения аски значения спецификаторы
*/

# define S_CHAR 'c'
# define S_STRING 's'
# define S_POINTER 'p'
# define S_PERCENT '%'
# define S_DECIMAL 'd'
# define S_OCTAL 'o'
# define S_HEX 'x'

# define F_MINUS (1 << 0)
# define F_ZERO (1 << 1)
# define F_PLUS (1 << 2)
# define F_SHARP (1 << 3)
# define F_SPACE (1 << 4)

# define F_HH (1 << 5)
# define F_H (1 << 6)
# define F_L (1 << 7)
# define F_LL (1 << 8)
# define F_J (1 << 9)
# define F_Z (1 << 10)

/*
**	основная структура хранения токенов
**	width		-	ширина
**	precision	-	точность
**	flags		-	дополнительные флаги:
**		none	print normally (right justify, space fill)	0
**		-		left justify								2^0
**		0		leading zero fill							2^1
**		+		print plus on positive numbers				2^2
**		#		multi use									2^3
**		space	invisible plus sign							2^4
**		hh		char										2^5
**		h		short										2^6
**		l		long										2^7
**		ll		long long									2^8
**		j		intmax_t									2^9
**		z		size_t										2^10
**	за каждый флаг отвичает свой бит, например если считали с флагами
**	- и +, то значени flags=5
*/

typedef	struct	s_token
{
	char		spec;
	char		width;
	char		precision;
	int			flags;
}				t_token;

int				ft_printf(const char *f, ...);
int				process_token(const char *f, int *i, va_list ap);

int				print_char(char c, t_token *tok);
int				print_string(char *s, t_token *tok);
int				print_no_flag(char *str, int w, int p, char c);
int				print_with_flag(char *str, int w, int p, char c);
int				print_pointer(unsigned long long int n, t_token *tok);
int				print_decimal(long long int n, t_token *tok);
int				print_number(char *str, t_token *tok, int sign);
int				print_octal(size_t n, t_token *tok);
int				print_hex(size_t n, t_token *tok);

#endif
