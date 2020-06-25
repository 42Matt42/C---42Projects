#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*alst;
	int		fd;
	int		fd2;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd == -1 || fd2 == -1 || ft_last_check(fd2) == -1
			|| (alst = ft_read_tetri(fd)) == NULL)
	{
		close(fd);
		close(fd2);
		ft_putstr("error\n");
		return (-1);
	}
	close(fd);
	close(fd2);
	ft_solve(alst);
	ft_free_list(alst);
	return (0);
}
