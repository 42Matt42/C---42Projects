/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:17:27 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 22:41:55 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dest_size;
	size_t	i;

	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (size < dest_size)
		return (size + src_size);
	while (src[i] && i + dest_size + 1 < size)
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[i + dest_size] = 0;
	return (dest_size + src_size);
}
