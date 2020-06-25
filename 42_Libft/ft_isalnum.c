/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:57:42 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/26 23:01:22 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns true if the int corresponds to a letter or a digit in the ascii table 

#include "libft.h"

int		ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
