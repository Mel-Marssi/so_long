/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:33:36 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/30 20:09:37 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_count(t_num x)
{
	if (x.c == 0)
		(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
	if (x.p != 1)
		(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
	if (x.e != 1)
		(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
}

void	if_map(char map)
{
	if (map != 'P' && map != 'E'
		&& map != 'C' && map != '1'
		&& map != '0' && map != '\n')
		(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
}

void	check_char_map(char **map, size_t size, size_t im)
{
	t_num	x;

	init(&x);
	while (map[x.i] && x.i <= im)
	{
		x.j = 0;
		while (map[x.i][x.j])
		{
			if_map(map[x.i][x.j]);
			if (size != ft_strlen(map[x.i]))
				(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
			if (map[x.i][x.j] == 'P')
				x.p++;
			if (map[x.i][x.j] == 'E')
				x.e++;
			if (map[x.i][x.j] == 'C')
				x.c++;
			x.j++;
		}
		x.i++;
		if (x.i == im)
			size--;
	}
	ft_count(x);
}

int	strlen_dbl(char	*av)
{
	int		i;
	int		fd0;
	char	*map;

	i = 0;
	fd0 = open(av, O_RDONLY);
	if (fd0 == -1)
		(ft_printf("Error\nMap not Found\n"), exit (-1));
	map = get_next_line(fd0);
	if (map == NULL)
		(ft_printf("Error\nMap not Found\n"), exit (-1));
	while (map)
	{
		free(map);
		map = get_next_line(fd0);
		i++;
	}
	free(map);
	return (i);
}

char	**get_map(char *av, size_t size)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(ft_printf("Error\nMap not Found!\n"), exit (-1));
	i = 0;
	map = ft_calloc(size + 1, sizeof(char *));
	if (map == NULL)
		exit(-1);
	map[0] = get_next_line(fd);
	if (map[0] == NULL)
		(ft_printf("Error\nMap not Found!\n"), exit (-1));
	while (map[i++])
		map[i] = get_next_line(fd);
	return (map);
}
