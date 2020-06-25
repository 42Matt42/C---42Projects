/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:31:01 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:53:04 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_key_fractal(int key, t_mlx *all)
{
	if (key == 38)
		all->cam->fractal = 'j';
	else if (key == 5)
		all->cam->fractal = 'g';
	else if (key == 46)
		all->cam->fractal = 'm';
	else if (key == 1)
		all->cam->fractal = 's';
	else if (key == 45)
		all->cam->fractal = 'n';
	ft_render(all);
}

static void	ft_key_cam(int key, t_mlx *all)
{
	if (key == 121)
	{
		if (all->fra->iter >= 40 && all->fra->iter <= 100)
			all->fra->iter -= 20;
		else if (all->fra->iter > 100 && all->fra->iter <= 200)
			all->fra->iter = 100;
		else if (all->fra->iter >= 200)
			all->fra->iter -= 100;
	}
	else if (key == 116)
	{
		if (all->fra->iter <= 100)
			all->fra->iter += 20;
		else if (all->fra->iter <= 300)
			all->fra->iter += 100;
	}
	ft_render(all);
}

static void	ft_key_move(int key, t_mlx *all)
{
	if (key == 69)
		ft_zoom_out(all, all->win->width / 2, all->win->height / 2);
	if (key == 78)
		ft_zoom_in(all, all->win->width / 2, all->win->height / 2);
	ft_render(all);
}

static void	ft_key_color(int key, t_mlx *all)
{
	if (key == 83 && all->cam->r > 0)
		all->cam->r--;
	if (key == 89 && all->cam->r < 255)
		all->cam->r++;
	if (key == 84 && all->cam->g > 0)
		all->cam->g--;
	if (key == 91 && all->cam->g < 255)
		all->cam->g++;
	if (key == 85 && all->cam->b > 0)
		all->cam->b--;
	if (key == 92 && all->cam->b < 255)
		all->cam->b++;
	ft_render(all);
}

int			ft_key_hook(int key, void *para)
{
	t_mlx *all;

	all = (t_mlx *)para;
	if (key == 53)
	{
		ft_close(all);
		return (1);
	}
	if (key == 121 || key == 116)
		ft_key_cam(key, all);
	if (key == 1 || key == 5 || key == 15 || key == 38
		|| key == 45 || key == 46)
		ft_key_fractal(key, all);
	if (key == 83 || key == 84 || key == 85 || key == 89
		|| key == 91 || key == 92 || key == 116 || key == 121)
		ft_key_color(key, all);
	if (key == 69 || key == 78 || key == 84 || key == 86
		|| key == 88 || key == 91)
		ft_key_move(key, all);
	return (0);
}
