/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:47:41 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/25 17:31:26 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies n bytes from memory area src to memory area dst
// It is recommanded to use memmove to protect from overlap

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (n == 0 || dst == src)
		return (dst);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n--)
		d[n] = s[n];
	return (dst);
}
