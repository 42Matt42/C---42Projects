/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:37:08 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:40:38 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void				ft_mandelbrot(t_mlx *all)
{
	int				x;
	int				y;
	int				i;
	t_complex		z;
	t_complex		c;

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
			while (++i <= all->fra->iter && ft_complex_mod(z) <= 4.0)
				ft_complex_calc(&z, c);
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
		}
	}
}
