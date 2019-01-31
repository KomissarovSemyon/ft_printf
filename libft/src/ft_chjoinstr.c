/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chjoinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:10:07 by amerlon-          #+#    #+#             */
/*   Updated: 2019/01/31 18:19:15 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chjoinstr(char c, char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	if (c == '\0')
		return (ft_strdup(str));
	res = ft_strnew(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	res[0] = c;
	while (str[i])
	{
		res[i + 1] = str[i];
		i++;
	}
	return (res);
}
