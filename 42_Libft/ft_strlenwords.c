/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenwords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:51:53 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 23:37:08 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_strlenwords(char *str, char c, int words)
{
	int		w;
	int		*recap;
	int		i;

	if (!(recap = (int*)malloc(sizeof(int) * words)))
		return (NULL);
	i = 0;
	w = 0;
	while (str[i] != '\0' && w < words)
	{
		recap[w] = 0;
		while (str[i] != c && str[i] != '\0')
		{
			recap[w] += 1;
			i++;
		}
		if (str[i] == c)
		{
			i++;
			w++;
		}
	}
	return (recap);
}
