/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:06:50 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/08 23:34:36 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			ft_exit(char *a)
{
	if (a != NULL)
	{
		ft_putstr(a);
		ft_putchar('\n');
	}
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	*all;
	char	c;

	c = ft_check_input(ac, av);
	if (!(all = ft_new_mlx()))
		return (-1);
	if (!(all = ft_new_cam(all)))
		ft_exit("Error : malloc cam");
	all->cam->fractal = c;
	if (!(all = ft_new_win(all, av[0], 1080, 1080)))
		ft_exit("Error : malloc win");
	if (!(all = ft_new_fract(all)))
		ft_exit("Error : malloc fract");
	ft_render(all);
	mlx_key_hook(all->win->win_ptr, ft_key_hook, (void*)all);
	mlx_hook(all->win->win_ptr, 17, 0, ft_close, all);
	mlx_hook(all->win->win_ptr, 4, 0, ft_mouse_press, (void*)all);
	mlx_hook(all->win->win_ptr, 6, 0, ft_mouse_move, (void*)all);
	mlx_loop(all->mlx_ptr);
	return (0);
}

int			ft_close(t_mlx *all)
{
	mlx_destroy_window(all->mlx_ptr, all->win->win_ptr);
	ft_memdel((void**)&(all->fra));
	ft_memdel((void**)&(all->cam));
	ft_memdel((void**)&(all->win->img_str));
	ft_memdel((void**)&(all->win->img_ptr));
	ft_memdel((void**)&(all->win));
	ft_memdel((void**)&(all->mlx_ptr));
	ft_memdel((void**)&(all));
	exit(0);
	return (0);
}
