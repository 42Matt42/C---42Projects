/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:37:07 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/05 00:41:35 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return int value from ascii number (string)

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		value;
	int		dash;

	i = 0;
	value = 0;
	dash = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == ' ' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		i++;
		dash = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (str[i] - 48) + value * 10;
		i++;
	}
	return (dash * value);
}
