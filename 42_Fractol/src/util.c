/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:30:51 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:42:58 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_mlx		*ft_new_mlx(void)
{
	t_mlx	*all;

	if (!(all = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(all->mlx_ptr = mlx_init()))
		return (NULL);
	return (all);
}

t_mlx		*ft_new_win(t_mlx *all, char *s, int width, int height)
{
	int bpp;
	int	s_l;
	int	endian;

	if (!(all->win = (t_win *)ft_memalloc(sizeof(t_win))))
		return (NULL);
	all->win->img_ptr = mlx_new_image(all->mlx_ptr, width, height);
	all->win->img_str = (unsigned int*)mlx_get_data_addr(all->win->img_ptr,
			&bpp, &s_l, &endian);
	if (all->win->img_ptr == NULL || all->win->img_str == NULL)
		return (NULL);
	all->win->name = s;
	all->win->width = width;
	all->win->height = height;
	all->win->win_ptr = mlx_new_window(all->mlx_ptr,
			all->win->width, all->win->height, all->win->name);
	return (all);
}

t_mlx		*ft_new_cam(t_mlx *all)
{
	if (!(all->cam = (t_cam *)ft_memalloc(sizeof(t_cam))))
		ft_exit("Error : malloc cam");
	all->cam->fractal = 'm';
	all->cam->mouse_left = 0;
	all->cam->mouse_right = 0;
	all->cam->x_mouse = 0;
	all->cam->y_mouse = 0;
	all->cam->o = 0;
	all->cam->r = 4;
	all->cam->g = 12;
	all->cam->b = 6;
	all->cam->color = 0x000001;
	all->cam->color_end = 0;
	return (all);
}

t_mlx		*ft_new_fract(t_mlx *all)
{
	if (!(all->fra = (t_fract*)ft_memalloc(sizeof(t_fract))))
		ft_exit("Error : malloc fract");
	all->fra->x_min = -3;
	all->fra->x_max = 3;
	all->fra->y_min = -3;
	all->fra->y_max = 3;
	all->fra->zoom_x = all->win->width
		/ ((all->fra->x_max - all->fra->x_min));
	all->fra->zoom_y = all->win->height
		/ ((all->fra->y_max - all->fra->y_min));
	all->fra->iter = 20;
	return (all);
}
