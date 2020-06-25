#include "../inc/fdf.h"

void	ft_fill_pix(t_mlx *mlx_all, int x, int y, unsigned int color)
{
	if (x >= 0 && x < mlx_all->win->width
			&& y >= 0 && y < mlx_all->win->height)
		mlx_all->win->img_str[y * mlx_all->win->width + x] =
			color + mlx_all->cam->opacity;
}
