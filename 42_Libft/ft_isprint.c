/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:23:20 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/26 23:24:37 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns true if the int corresponds to 
// a printable character in the ascii table 

#include "libft.h"

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
