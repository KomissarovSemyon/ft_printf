/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nchjoinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:29:35 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/13 21:50:54 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nchjoinstr(char *str, char c, int n)
{
	char	*res;
	int		i;
	int		j;

	if (n < 0)
		return (ft_strdup(str));
	res = ft_strnew(ft_strlen(str) + n);
	j = -1;
	while (n--)
		res[++j] = c;
	i = -1;
	while (str[++i])
		res[++j] = str[i];
	return (res);
}
