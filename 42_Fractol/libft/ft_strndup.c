/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:29:22 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 23:30:10 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*p;
	size_t	len;

	len = ft_strnlen(src, n);
	if (!(p = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (p)
	{
		ft_strncpy(p, src, (len));
		p[len] = '\0';
	}
	return (p);
}
