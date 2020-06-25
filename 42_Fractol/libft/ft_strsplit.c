/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:05:50 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 23:39:26 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_minimalloc(char **av, char *str, char c, int *lenwords)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	r;

	i = 0;
	r = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			j = 0;
			if (!(av[r] = (char*)malloc(sizeof(char) * (lenwords[r] + 1))))
				return (NULL);
			while (str[i] != c && str[i])
				av[r][j++] = str[i++];
			av[r++][j] = '\0';
		}
		if (str[i] == c)
			i++;
	}
	av[r] = 0;
	return (av);
}

char		**ft_strsplit(char const *s, char c)
{
	int		*lenwords;
	char	**av;
	char	*str;

	if (!s)
		return (NULL);
	if (!c)
		c = '0';
	str = (char*)s;
	lenwords = ft_strlenwords(str, c, ft_strwords(str, c));
	if (!(av = (char**)malloc(sizeof(char*) * (ft_strwords(str, c) + 1))))
		return (NULL);
	return (ft_minimalloc(av, str, c, lenwords));
}
