/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:37:04 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 19:07:03 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_len(int nb)
{
	int	len;
	int	i;

	len = 2;
	i = nb;
	while (i /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		len;

	neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		neg = 1;
		n *= -1;
	}
	len = ft_digit_len(n) + neg;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
