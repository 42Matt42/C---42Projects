/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:08:31 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/02 23:55:53 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer of a copy of the string src 
// with memory allocated appropriately (malloc)

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;

	if (!(p = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(p, src);
	return (p);
}
