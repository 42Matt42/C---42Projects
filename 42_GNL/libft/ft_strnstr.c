/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:21:22 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 22:54:33 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!n[0])
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (n[j] == haystack[i + j])
		{
			if (i + j == len)
				return (NULL);
			j++;
			if (!n[j])
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
