/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:12:36 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/02 23:42:52 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies len bytes from memory area src to memory area dst
// The copying side is chosen to prevent overlap in memory

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		i;

	d = dst;
	s = src;
	if (d >= s)
		while (len--)
			d[len] = s[len];
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
