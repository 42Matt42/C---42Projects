/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:38:50 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/02 23:37:42 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return ((void*)&d[i + 1]);
		i++;
	}
	return (NULL);
}
