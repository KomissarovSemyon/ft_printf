/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:09:57 by amerlon-          #+#    #+#             */
/*   Updated: 2019/02/03 14:27:23 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinnch(char **str, char c, int n)
{
	int		i;
	char	*res;

	res = ft_strnew(ft_strlen(*str) + n);
	if (!res)
		return (NULL);
	i = -1;
	while ((*str)[++i])
		res[i] = (*str)[i];
	while (n--)
		res[i++] = c;
	free(*str);
	*str = res;
	return (res);
}
