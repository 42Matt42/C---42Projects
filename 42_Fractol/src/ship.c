/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:25:14 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/07 18:51:41 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_ship(t_mlx *all, int x, int y, int i)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	double		tmp2;

	y = -1;
	while (++y < all->win->height)
	{
		x = -1;
		while (++x < all->win->width)
		{
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(x / all->fra->zoom_x + all->fra->x_min,
					y / all->fra->zoom_y + all->fra->y_min);
			i = -1;
			while (++i < all->fra->iter && ft_complex_mod(z) <= 4.0)
			{
				tmp = z.re;
				z.re = z.re * z.re - z.ir * z.ir + c.re;
				tmp2 = z.ir * tmp;
				z.ir = (tmp2 < 0) ? 2 * (tmp2 * -1) + c.ir : 2 * tmp2 + c.ir;
			}
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
		}
	}
}
