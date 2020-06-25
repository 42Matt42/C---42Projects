/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 23:17:41 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:17:45 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		ft_newton_calc(t_complex *z, t_complex *tmp, double *k)
{
	tmp->re = z->re;
	tmp->ir = z->ir;
	*k = (z->re * z->re + z->ir * z->ir) * (z->re * z->re + z->ir * z->ir);
	z->re = (2 * z->re * *k + z->re * z->re - z->ir * z->ir) / (3 * *k);
	z->ir = (2 * z->ir * (*k - tmp->re)) / (3 * *k);
	*k = (z->re - tmp->re) * (z->re - tmp->re)
		+ (z->ir - tmp->ir) * (z->ir - tmp->ir);
}

static void		ft_newton_calc2(t_complex *z, t_complex *tmp, double *k)
{
	tmp->re = z->re;
	tmp->ir = z->ir;
	*k = (z->re * z->re * z->re + z->ir * z->ir * z->ir)
		* (z->re * z->re * z->re + z->ir * z->ir * z->ir);
	z->re = (2 * z->re * *k + z->re * z->re * z->re - z->ir * z->ir * z->ir)
		/ (3 * *k);
	z->ir = (2 * z->ir * (*k - tmp->re)) / (3 * *k);
	*k = (z->re - tmp->re) * (z->re - tmp->re)
		+ (z->ir - tmp->ir) * (z->ir - tmp->ir);
}

int				ft_newton(t_mlx *all)
{
	t_complex	tmp;
	t_point		xy;
	int			i;
	double		k;
	t_complex	z;

	xy.y = -1;
	while (++(xy.y) < all->win->height)
	{
		xy.x = -1;
		while (++(xy.x) < all->win->width)
		{
			z = ft_new_complex(xy.x / all->fra->zoom_x + all->fra->x_min,
					xy.y / all->fra->zoom_y + all->fra->y_min);
			i = -1;
			k = 1.0;
			while (++i < all->fra->iter && k > 0.000001)
				ft_newton_calc(&z, &tmp, &k);
			ft_fill_pixel(all, xy.x, xy.y, ft_get_color(all, i));
		}
	}
	return (0);
}

int				ft_newton2(t_mlx *all)
{
	t_complex	tmp;
	t_point		xy;
	int			i;
	double		k;
	t_complex	z;

	xy.y = -1;
	while (++(xy.y) < all->win->height)
	{
		xy.x = -1;
		while (++(xy.x) < all->win->width)
		{
			z = ft_new_complex(xy.x / all->fra->zoom_x + all->fra->x_min,
					xy.y / all->fra->zoom_y + all->fra->y_min);
			i = -1;
			k = 1.0;
			while (++i < all->fra->iter && k > 0.000001)
				ft_newton_calc2(&z, &tmp, &k);
			ft_fill_pixel(all, xy.x, xy.y, ft_get_color(all, i));
		}
	}
	return (0);
}
