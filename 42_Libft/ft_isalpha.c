/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:40:26 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 18:58:13 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns true if the int corresponds to a letter in the ascii table 

#include "libft.h"

int		ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
