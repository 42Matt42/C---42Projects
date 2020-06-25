/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:53:25 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/02 23:27:04 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	i = 0;
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
