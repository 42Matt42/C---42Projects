/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:45:12 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:59:21 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		ft_legend(t_mlx *all)
{
	// char *nb;

	// nb = ft_itoa(all->fra->iter);
	// mlx_string_put(all->mlx_ptr, all->win->win_ptr, 0, 20, 0x00FFFC,
	// 	" iterations = ");
	// mlx_string_put(all->mlx_ptr, all->win->win_ptr, 140, 20, 0x00FFFC, nb);
	mlx_string_put(all->mlx_ptr, all->win->win_ptr, 0, 40, 0x00FFFC,
		" fractal    = ");
	mlx_string_put(all->mlx_ptr, all->win->win_ptr, 140, 40, 0x00FFFC,
		&all->cam->fractal);
}

void		ft_render(t_mlx *all)
{
	if (all->cam->fractal == 'm')
		ft_mandelbrot(all);
	else if (all->cam->fractal == 'j')
		ft_julia(all, all->cam->x_mouse, all->cam->y_mouse);
	else if (all->cam->fractal == 's')
		ft_ship(all, -1, -1, -1);
	else if (all->cam->fractal == 'g')
		ft_newton2(all);
	else if (all->cam->fractal == 'n')
		ft_newton(all);
	mlx_clear_window(all->mlx_ptr, all->win->win_ptr);
	mlx_put_image_to_window(all->mlx_ptr, all->win->win_ptr,
			all->win->img_ptr, 0, 0);
	ft_legend(all);
}

char		ft_check_input(int ac, char **av)
{
	char	c;

	c = 'c';
	if (ac != 2)
	{
		ft_use();
		exit(0);
	}
	if (av[1][0] == 'm' && ft_strlen(av[1]) == 1)
		c = 'm';
	else if (av[1][0] == 'j' && ft_strlen(av[1]) == 1)
		c = 'j';
	else if (av[1][0] == 's' && ft_strlen(av[1]) == 1)
		c = 's';
	else if (av[1][0] == 'g' && ft_strlen(av[1]) == 1)
		c = 'g';
	else if (av[1][0] == 'n' && ft_strlen(av[1]) == 1)
		c = 'n';
	else
	{
		ft_use();
		exit(0);
	}
	return (c);
}

void		ft_use(void)
{
	ft_putstr("\033[4;36musage\033[0;36m: ./fractol \033[0m");
	ft_putstr("\033[1;36m[m || j || s || g || n]\n\033[0m");
	ft_putstr("\033[0;34mEach letter corresponds to a fractal\n\033[0;0m");
}
