/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <msaubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:44:40 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/20 11:59:59 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int a;

	a = nb - 1;
	if (nb >= 0 && nb <= 12)
	{
		if (nb == 0 || nb == 1)
			return (1);
		while (a >= 1)
		{
			nb *= a;
			a--;
		}
		return (nb);
	}
	else
		return (0);
}
