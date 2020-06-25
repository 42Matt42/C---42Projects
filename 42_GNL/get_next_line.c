/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:33:43 by msaubin           #+#    #+#             */
/*   Updated: 2019/02/02 06:00:59 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_memmove_bis(char *d, char *s, int len)
{
	int		i;

	if (len < 0)
		return (s);
	if (d >= s)
		while (len--)
			d[len] = s[len];
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

static int		ft_check_n(char *save)
{
	int	i;

	i = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	if (i != 0)
		return (0);
	return (-1);
}

static int		ft_get_line(int fd, char *buf, char **save)
{
	int		ret;
	char	*address;

	while ((ret = read(fd, buf, BUFF_SIZE)) != -1)
	{
		buf[ret] = '\0';
		if (ret != 0)
		{
			if (*save != NULL)
			{
				address = *save;
				*save = ft_strjoin(*save, buf);
				free(address);
			}
			else
				*save = ft_strdup(buf);
		}
		if (*save == NULL)
			return (-1);
		if (ft_check_n(*save) == 1 || (ret == 0 && ft_check_n(*save) >= 0))
			return (1);
		else if (ret == 0 && !**save)
			return (0);
	}
	return (-1);
}

static int		ft_clean_static(char *save)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	y = ft_strlen(save);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	y = (y - i - 1);
	if (y < 0)
		y = 0;
	save = ft_memmove_bis(&save[0], &save[i + 1], y);
	save[y] = '\0';
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	char		buf[BUFF_SIZE + 1];
	static char	*save = NULL;

	i = 0;
	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (save != NULL && save[0] != '\0')
		ft_clean_static(save);
	if ((i = ft_get_line(fd, buf, &save)) <= 0)
		return (i);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	i--;
	while (i >= 0)
	{
		(*line)[i] = save[i];
		i--;
	}
	return (1);
}
