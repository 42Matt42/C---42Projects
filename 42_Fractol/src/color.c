/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:16:23 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/06 18:35:07 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

unsigned int	ft_get_color(t_mlx *all, int i)
{
	unsigned int	color;
	unsigned int	tmp;

	if (i >= all->fra->iter)
		return (all->cam->color_end);
	tmp = (i * all->cam->o) % 0xFF;
	color = tmp;
	tmp = (i * all->cam->r) % 0xFF;
	color = (color << 8) + tmp;
	tmp = (i * all->cam->g) % 0xFF;
	color = (color << 8) + tmp;
	tmp = (i * all->cam->b) % 0xFF;
	color = (color << 8) + tmp;
	return (color);
}
