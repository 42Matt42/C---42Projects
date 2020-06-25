#include "fillit.h"

t_map		*ft_new_map(char size)
{
	t_map	*new;
	int		i;
	int		j;

	new = (t_map *)ft_memalloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->size = size;
	new->array = (char **)ft_memalloc(size * sizeof(char *));
	if (new->array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new->array[i] = ft_strnew(size * sizeof(char));
		j = 0;
		while (j < size)
		{
			new->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (new);
}

t_tetri		*ft_new_tetri(char **tetri, int height, int width)
{
	t_tetri *new;

	new = (t_tetri*)(ft_memalloc(sizeof(t_tetri)));
	new->height = height;
	new->width = width;
	new->tetri = tetri;
	return (new);
}

char		**ft_new_tab_2d(int height, int width)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(height * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!(new[i] = (char *)malloc(sizeof(char) * (width + 1))))
		{
			while (i > 0)
			{
				i--;
				ft_memdel((void **)&new[i]);
			}
			ft_memdel((void **)&new);
			return (NULL);
		}
		new[i][width + 1] = '\0';
		i++;
	}
	return (new);
}

int			ft_high_sqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}
