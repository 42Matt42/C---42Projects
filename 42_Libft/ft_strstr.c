/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:23:24 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 22:57:17 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *n)
{
	size_t	i;
	size_t	j;

	if (!n[0])
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (n[j] == haystack[i + j])
		{
			j++;
			if (!n[j])
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
