/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <msaubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:54:57 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/20 12:39:00 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *v;
	int i;

	if (min >= max)
	{
		v = 0;
		return (v);
	}
	if (!(v = (int*)malloc(sizeof(int) * (max - min))))
		return (0);
	i = 0;
	while (i < max - min)
	{
		v[i] = min + i;
		i++;
	}
	return (v);
}
