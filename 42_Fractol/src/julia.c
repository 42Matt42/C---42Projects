/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:12:20 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:40:58 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void				ft_calcul(t_mlx *all, t_complex z, t_complex c, t_point xy)
{
	int				i;

	i = -1;
	while (++i <= all->fra->iter && ft_complex_mod(z) <= 4.0)
		ft_complex_calc(&z, c);
	ft_fill_pixel(all, xy.x, xy.y, ft_get_color(all, i));
}

int					ft_julia(t_mlx *all, int x_mouse, int y_mouse)
{
	t_point			xy;
	t_complex		z;
	t_complex		c;

	xy.y = -1;
	if (!(y_mouse >= 0 && y_mouse <= all->win->height
				&& x_mouse >= 0 && x_mouse <= all->win->width))
		return (-1);
	while (++(xy.y) < all->win->height)
	{
		xy.x = -1;
		while (++(xy.x) < all->win->width)
		{
			z = ft_new_complex(xy.x / all->fra->zoom_x + all->fra->x_min,
					xy.y / all->fra->zoom_y + all->fra->y_min);
			c = ft_new_complex(x_mouse / all->fra->zoom_x + all->fra->x_min,
					y_mouse / all->fra->zoom_y + all->fra->y_min);
			ft_calcul(all, z, c, xy);
		}
	}
	return (0);
}
