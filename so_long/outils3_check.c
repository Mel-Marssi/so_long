/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils3_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:36:04 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/24 21:36:36 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
