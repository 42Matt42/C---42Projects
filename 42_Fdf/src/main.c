#include "../inc/fdf.h"

static int	ft_exit_cross(t_mlx *mlx_all)
{
	ft_close(mlx_all, NULL);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx_all;

	if (argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_close(NULL, " map_file\n");
	}
	if ((mlx_all = ft_new_mlx()) == NULL)
		ft_close(NULL, "Error : Malloc Mlx\n");
	if ((mlx_all = ft_new_win(mlx_all, "fdf", 1920, 1080)) == NULL)
		ft_close(mlx_all, "Error : Malloc t_win\n");
	if ((mlx_all = ft_new_cam(mlx_all)) == NULL)
		ft_close(mlx_all, "Error : Malloc t_cam\n");
	if (ft_parse_map(argv[1], mlx_all) == -1)
		ft_close(mlx_all, "Error : Map parsing || Malloc t_map\n");
	ft_set_iso(mlx_all, 'r');
	ft_render(mlx_all);
	mlx_key_hook(mlx_all->win->win_ptr, ft_key_hook, (void *)mlx_all);
	mlx_mouse_hook(mlx_all->win->win_ptr, ft_mouse_hook, (void *)mlx_all);
	mlx_hook(mlx_all->win->win_ptr, 17, 0, ft_exit_cross, (void *)mlx_all);
	mlx_loop(mlx_all->mlx_ptr);
	return (0);
}

int			ft_close(t_mlx *mlx_all, char *e)
{
	if (e != NULL)
		ft_putstr(e);
	if (mlx_all != NULL && mlx_all->mlx_ptr != NULL
			&& mlx_all->win->win_ptr != NULL)
		mlx_destroy_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
	exit(0);
	return (0);
}
