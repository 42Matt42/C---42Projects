#include "../inc/fdf.h"
#include <fcntl.h>

int		ft_parse_map(char *file, t_mlx *mlx_all)
{
	char	*line;
	int		fd;
	int		i;

	if ((mlx_all->map->height = ft_get_height(file)) == 0)
		return (-1);
	mlx_all->map->map = (t_point ***)ft_memalloc(sizeof(t_point **) *
			(mlx_all->map->height + 1));
	if ((fd = open(file, O_RDONLY)) < 0 || mlx_all->map->map == NULL)
		return (-1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line(line) == -1
				|| ft_get_map(mlx_all, ft_strsplit(line, ' '), i) == -1)
			return (-1);
		ft_memdel((void **)&line);
		i++;
	}
	return (0);
}

int		ft_get_map(t_mlx *mlx_all, char **line, int k)
{
	int		i;
	int		len;

	len = 0;
	while (line[len] != '\0')
		len++;
	if (mlx_all->map->len != -1 && (mlx_all->map->len != len))
		return (-1);
	if (mlx_all->map->len == -1)
		mlx_all->map->len = len;
	if (!(mlx_all->map->map[k] =
		(t_point **)ft_memalloc(sizeof(t_point *) * (len + 1))))
		return (-1);
	mlx_all->map->map[k][len + 1] = NULL;
	i = 0;
	while (line[i] != '\0')
	{
		if (!(mlx_all->map->map[k][i] = ft_newpoint(i, k, line[i])))
			return (-1);
		ft_memdel((void **)&(line[i]));
		i++;
	}
	ft_memdel((void **)&line);
	return (0);
}

int		ft_check_line(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i + j] != '\0')
	{
		j = 0;
		if (line[i] == ',')
		{
			j = 1;
			while (line[i + j] != ' ' && line[i + j] != '\0')
			{
				if ((j == 1 && line[i + j] == '0')
						|| (j == 2 && line[i + j] == 'x')
						|| (j > 2 && j < 9 && ft_ishexa(line[i + j]) == 1))
					j++;
				else
					return (-1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
