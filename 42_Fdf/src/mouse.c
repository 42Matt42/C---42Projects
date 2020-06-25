#include "../inc/fdf.h"

int		ft_mouse_hook(int button, int x, int y, void *para)
{
	t_mlx		*mlx_all;

	mlx_all = (t_mlx *)para;
	x = 0;
	y = 0;
	if (button == 4 && mlx_all->cam->di_x < 100)
	{
		mlx_all->cam->di_x *= 1.2;
		mlx_all->cam->di_y *= 1.2;
		mlx_all->cam->di_z *= 1.2;
		ft_render(mlx_all);
	}
	else if (button == 5 && mlx_all->cam->di_x > 3)
	{
		mlx_all->cam->di_x /= 1.2;
		mlx_all->cam->di_y /= 1.2;
		mlx_all->cam->di_z /= 1.2;
		ft_render(mlx_all);
	}
	return (0);
}
