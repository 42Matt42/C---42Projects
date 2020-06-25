#include "../inc/fdf.h"

t_mlx		*ft_new_mlx(void)
{
	t_mlx	*new;

	if ((new = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((new->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	if ((new->map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	new->map->len = -1;
	return (new);
}

t_mlx		*ft_new_win(t_mlx *mlx_all, char *s, int width, int height)
{
	int bpp;
	int	s_l;
	int	endian;

	if ((mlx_all->win = (t_win *)ft_memalloc(sizeof(t_win))) == NULL)
		ft_close(NULL, "Error : Malloc t_win\n");
	mlx_all->win->name = s;
	mlx_all->win->width = width;
	mlx_all->win->height = height;
	if (!(mlx_all->win->win_ptr = mlx_new_window(mlx_all->mlx_ptr,
			mlx_all->win->width, mlx_all->win->height, mlx_all->win->name)))
		return (NULL);
	if (!(mlx_all->win->img_ptr =
				mlx_new_image(mlx_all->mlx_ptr, width, height)))
		return (NULL);
	mlx_all->win->img_str = (unsigned int *)
		mlx_get_data_addr(mlx_all->win->img_ptr, &bpp, &s_l, &endian);
	mlx_all->win->x_line = 0;
	mlx_all->win->y_line = 0;
	return (mlx_all);
}

t_mlx		*ft_new_cam(t_mlx *mlx_all)
{
	if ((mlx_all->cam = (t_cam *)ft_memalloc(sizeof(t_cam))) == NULL)
		return (NULL);
	mlx_all->cam->opacity = 0;
	mlx_all->cam->proj = 'i';
	return (mlx_all);
}

int			ft_ishexa(char c)
{
	if (ft_isdigit(c) == 1
			|| ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
		return (1);
	return (0);
}

t_point		*ft_newpoint(int x, int y, char *line)
{
	t_point		*new;
	int			j;
	char		*rgb;

	if ((new = (t_point *)ft_memalloc(sizeof(t_point))) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = ft_atoi(line);
	j = 0;
	while (line[j] != ',' && line[j] != '\0')
		j++;
	if (line[j] == ',')
	{
		rgb = ft_strsub(line, j + 3, 8);
		new->color = ft_atoi_base(rgb, 16);
		ft_memdel((void **)&rgb);
	}
	else
		new->color = ft_atoi_base("FF0000", 16);
	return (new);
}
