/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:49:07 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/28 19:24:21 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns true if the int corresponds to an uppercase letter in the ascii table

#include "libft.h"

int		ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}
