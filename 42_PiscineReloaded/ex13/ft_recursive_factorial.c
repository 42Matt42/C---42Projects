/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <msaubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:03:10 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/20 12:06:46 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb >= 0 && nb <= 12)
	{
		if (nb == 0 || nb == 1)
			return (1);
		return (nb * ft_recursive_factorial(nb - 1));
	}
	else
		return (0);
}
