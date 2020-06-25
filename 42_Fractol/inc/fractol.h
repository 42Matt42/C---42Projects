/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:09:03 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 00:42:21 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_complex
{
	double			re;
	double			ir;
}					t_complex;

typedef struct		s_win
{
	void			*win_ptr;
	int				width;
	int				height;
	void			*img_ptr;
	unsigned int	*img_str;
	char			*name;
}					t_win;

typedef struct		s_cam
{
	int				mouse_left;
	int				mouse_right;
	int				x_mouse;
	int				y_mouse;
	unsigned int	color;
	unsigned int	color_end;
	int				o;
	int				r;
	int				g;
	int				b;
	char			fractal;
}					t_cam;

typedef struct		s_fract
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			zoom_x;
	double			zoom_y;
	int				iter;
}					t_fract;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	t_win			*win;
	t_cam			*cam;
	t_fract			*fra;
}					t_mlx;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;
/*
**					main.c
*/
int					ft_exit(char *a);
int					ft_close(t_mlx *all);
/*
**					key_event.c
*/
int					ft_key_hook(int key, void *para);
/*
**					mouse_event.c
*/
int					ft_mouse_press(int key, int x, int y, void *param);
int					ft_mouse_move(int x, int y, void *param);
void				ft_zoom_in(t_mlx *all, int x, int y);
void				ft_zoom_out(t_mlx *all, int x, int y);
/*
**					fractol_mb.c
*/
void				ft_mandelbrot(t_mlx *all);
/*
**					julia.c
*/
int					ft_julia(t_mlx *all, int x_mouse, int y_mouse);
void				ft_calcul(t_mlx *all, t_complex z, t_complex c, t_point p);
/*
**					util.c
*/
t_mlx				*ft_new_mlx(void);
t_mlx				*ft_new_win(t_mlx *all, char *s, int width, int height);
t_mlx				*ft_new_cam(t_mlx *all);
t_mlx				*ft_new_fract(t_mlx *all);
/*
**					math.c
*/
t_complex			ft_new_complex(double re, double ir);
void				ft_complex_calc(t_complex *z, t_complex c);
double				ft_complex_mod(t_complex z);
/*
**					draw.c
*/
void				ft_legend(t_mlx *all);
void				ft_render(t_mlx *all);
char				ft_check_input(int ac, char **av);
void				ft_use(void);
/*
**					fill_pixel.c
*/
void				ft_fill_pixel(t_mlx *mlx_all, int x, int y
									, unsigned int color);
/*
** 					ship.c
*/
void				ft_ship(t_mlx *all, int x, int y, int i);
/*
**					color.c
*/
unsigned int		ft_get_color(t_mlx *all, int i);
/*
**					newton.c
*/
int					ft_newton(t_mlx *all);
int					ft_newton2(t_mlx *all);
#endif
