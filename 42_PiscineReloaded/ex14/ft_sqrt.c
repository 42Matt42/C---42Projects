/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <msaubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:11:03 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/21 20:43:02 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int c;
	int divide;

	c = 1;
	divide = nb / 2;
	if (nb < 0)
		return (0);
	while (c <= divide && c * c != nb)
		c++;
	if (c >= divide)
		return (0);
	else
		return (c);
}
