/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:37:05 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/30 18:59:02 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	norm_wall0(char map)
{
	if (map != '1' && map != '\n')
		(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
}

void	norm_wall1(char map)
{
	if (map != '1')
		(ft_printf("Error\nMap Not Valid!\n"), exit(-1));
}

void	check_wall(char **map, t_dir x)
{
	while (map[0][x.y])
		norm_wall0(map[0][x.y++]);
	while (map[x.x])
		norm_wall1(map[x.x++][0]);
	x.y = 0;
	while (map[x.xm][x.y])
		norm_wall0(map[x.xm][x.y++]);
	x.x = 0;
	while (map[x.x])
		norm_wall1(map[x.x++][x.ym - 1]);
}

void	check_map(char *av)
{
	char	**map;
	char	**m;
	t_dir	x;
	t_pos	player;

	map = get_map(av, strlen_dbl(av));
	m = get_map(av, strlen_dbl(av));
	check_char_map(map, ft_strlen(map[0]), strlen_dbl(av) - 1);
	init2(&x, strlen_dbl(av) - 1, ft_strlen(map[0]));
	check_wall(map, x);
	player = get_pos(map, 'P');
	flod_fill(map, player.x, player.y);
	check_path(map);
	flod_exit(m, player.x, player.y);
	check_exit(m);
	ft_free_split(map);
	ft_free_split(m);
}
