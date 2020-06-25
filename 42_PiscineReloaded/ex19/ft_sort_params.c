/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <msaubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:08:24 by msaubin           #+#    #+#             */
/*   Updated: 2018/11/20 12:33:26 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		ft_putchar(str[j]);
		j++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a])
		a++;
	return (s1[a] - s2[a]);
}

int		ft_show(char *p)
{
	ft_putstr(p);
	ft_putchar('\n');
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*t;

	if (argc == 0)
		return (0);
	i = 0;
	while (++i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) < 0)
		{
			t = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = t;
			i = 0;
		}
	}
	i = argc;
	while (--i > 0)
		ft_show(argv[i]);
	return (0);
}
