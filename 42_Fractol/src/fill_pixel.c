/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:10:07 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/05 21:54:44 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_fill_pixel(t_mlx *all, int x, int y, unsigned int color)
{
	if (x >= 0 && x < all->win->width && y >= 0 && y < all->win->height)
		all->win->img_str[y * all->win->width + x] = color;
}
