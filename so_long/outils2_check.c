/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:37:05 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/21 21:18:26 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	norm_wall0(char map)
{
	if (map != '1' && map != '\n')
		(ft_printf("Map Not Valid!\n"), exit(-1));
}

void	norm_wall1(char map)
{
	if (map != '1')
		(ft_printf("Map Not Valid!\n"), exit(-1));
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
	t_dir	x;

	map = get_map(av, strlen_dbl(av));
	check_char_map(map, ft_strlen(map[0]), strlen_dbl(av) - 1);
	init2(&x, strlen_dbl(av) - 1, ft_strlen(map[0]));
	check_wall(map, x);
}
