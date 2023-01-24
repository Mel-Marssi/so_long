/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workshop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:04:10 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/24 21:29:03 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	get_pos(char **map)
{
	int		i;
	int		j;
	t_pos	x;

	i = 0;
	init3(&x);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				x.x = i;
				x.y = j;
				return (x);
			}
			j++;
		}
		i++;
	}
	return (x);
}

void	flod_fill(char **map, int i, int j)
{
	if (map[i][j] == '\0')
		return ;
	if ((map[i][j] == '\n' || map[i][j] == '1'
	|| map[i][j] == '*'))
		return ;
	map[i][j] = '*';
	flod_fill(map, i - 1, j);
	flod_fill(map, i + 1, j);
	flod_fill(map, i, j - 1);
	flod_fill(map, i, j + 1);
}

void	check_path(char **map)
{
	t_num	x;

	init(&x);
	while (map[x.i])
	{
		x.j = 0;
		while (map[x.i][x.j])
		{
			if (map[x.i][x.j] == 'E' || map[x.i][x.j] == 'C'
			|| map[x.i][x.j] == 'P')
				(ft_printf("Path Not Valid!\n"), exit(-1));
			x.j++;
		}
		x.i++;
	}
}

int	main(int ac, char **av)
{
	t_pos	player;
	char	**map;

	if (ac <= 1)
		exit(-1);
	check_map(av[1]);
	map = get_map(av[1], strlen_dbl(av[1]));
	player = get_pos(map);
	flod_fill(map, player.x, player.y);
	check_path(map);
}
