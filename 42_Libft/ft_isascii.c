/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:03:16 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/26 23:04:42 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns true if the int corresponds to an ascii in the ascii table 

#include "libft.h"

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
