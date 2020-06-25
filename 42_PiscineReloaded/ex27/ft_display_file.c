/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <msaubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:38:15 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/21 19:18:27 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_display_file(char *name)
{
	char	buff[BUFF_SIZE + 1];
	int		file;
	int		bis;

	file = open(name, O_RDONLY);
	bis = read(file, buff, BUFF_SIZE);
	buff[bis] = '\0';
	ft_putstr(buff);
	close(file);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	if (argc == 2)
		ft_display_file(argv[1]);
	return (0);
}
