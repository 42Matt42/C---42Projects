#include "../inc/fdf.h"

t_bres		*ft_new_bres(int x1, int y1, int x2, int y2)
{
	t_bres	*new;

	if ((new = (t_bres *)ft_memalloc(sizeof(t_bres))) == NULL)
		return (NULL);
	new->x1 = x1;
	new->y1 = y1;
	new->x2 = x2;
	new->y2 = y2;
	new->dx = x1 - x2;
	new->dy = y1 - y2;
	new->x_inc = (new->dx < 0) ? 1 : -1;
	new->y_inc = (new->dy < 0) ? 1 : -1;
	new->i = 1;
	new->dx = fabs(new->dx);
	new->dy = fabs(new->dy);
	new->error = (new->dx >= new->dy) ? new->dx / 2 : new->dy / 2;
	return (new);
}

void		ft_draw_line(t_mlx *mlx_all, int x, int y, int color)
{
	t_bres *bres;

	if (!(bres = ft_new_bres(mlx_all->win->x_line, mlx_all->win->y_line, x, y)))
		ft_close(mlx_all, "Error : Malloc t_bres\n");
	while ((bres->i <= bres->dx && bres->dx >= bres->dy)
			|| (bres->i <= bres->dy && bres->dx <= bres->dy))
	{
		bres->i++;
		bres->error += (bres->dx >= bres->dy) ? bres->dy : bres->dx;
		if (bres->dx >= bres->dy)
			bres->x1 += bres->x_inc;
		else
			bres->y1 += bres->y_inc;
		if ((bres->error >= bres->dx && bres->dx >= bres->dy)
				|| (bres->error >= bres->dy && bres->dx <= bres->dy))
		{
			bres->error -= (bres->dx >= bres->dy) ? bres->dx : bres->dy;
			if (bres->dx >= bres->dy)
				bres->y1 += bres->y_inc;
			else
				bres->x1 += bres->x_inc;
		}
		ft_fill_pix(mlx_all, bres->x1, bres->y1, color);
	}
	ft_memdel((void **)&bres);
}

static void	ft_legend_details(t_mlx *mlx_all)
{
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 200, 0xFFFFFF
			, " I : Isometric view ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 220, 0xFFFFFF
			, " P : Parallel view  ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 240, 0xFFFFFF
			, " R : Reset position ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 340, 0xffffff
			, " </> : -/+ opacity  ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 380, 0xFFFFFF
			, " page down/page up  ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 400, 0xFFFFFF
			, " : -/+ perspective ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 440, 0xFFFFFF
			, " Use arrows to move ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 480, 0xFFFFFF
			, " Rotate the map     ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 500, 0xFFFFFF
			, " with the pav num   ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 520, 0xFFFFFF
			, " (4&6 - 2&8 - 3&7)  ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 1000, 0xFFFFFF
			, "     by tbeguin     ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 1020, 0xFFFFFF
			, "      & msaubin     ");
}

static void	ft_legend(t_mlx *mlx_all)
{
	int x;
	int y;

	y = 0;
	while (y < mlx_all->win->height)
	{
		x = 0;
		while (x++ < 200)
			ft_fill_pix(mlx_all, x, y, 0x6F00FF);
		y++;
	}
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 40, 0xffffff
			, "/******************/");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 100, 0xffffff
			, "     ~ LEGEND ~     ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 280, 0xFFFFFF
			, " -/+ OR scroll :    ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 300, 0xFFFFFF
			, " Change zoom     ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 160, 0xFFFFFF
			, " Esc : Exit         ");
	mlx_string_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, 0, 580, 0xFFFFFF
			, "/******************/");
	ft_legend_details(mlx_all);
}

void		ft_render(t_mlx *mlx_all)
{
	ft_bzero((void *)mlx_all->win->img_str, mlx_all->win->width
			* mlx_all->win->height * 4);
	if (mlx_all->cam->proj == 'i')
		ft_iso(mlx_all);
	else if (mlx_all->cam->proj == 'p')
		ft_parallel(mlx_all);
	ft_legend(mlx_all);
	mlx_clear_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr);
	mlx_put_image_to_window(mlx_all->mlx_ptr, mlx_all->win->win_ptr,
			mlx_all->win->img_ptr, 0, 0);
	ft_legend(mlx_all);
}
