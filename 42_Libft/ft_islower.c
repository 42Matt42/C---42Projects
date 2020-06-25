/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:45:52 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/28 19:23:56 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns true if the int corresponds to a lowercase letter in the ascii table

#include "libft.h"

int		ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}
