/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils4_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:32:17 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/31 14:01:14 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(void)
{
	exit(0);
}

void	flod_exit(char **map, int i, int j)
{
	if (map[i][j] == '\0')
		return ;
	if ((map[i][j] == '\n' || map[i][j] == '1'
	|| map[i][j] == '*') || map[i][j] == 'E')
		return ;
	map[i][j] = '*';
	flod_exit(map, i - 1, j);
	flod_exit(map, i + 1, j);
	flod_exit(map, i, j - 1);
	flod_exit(map, i, j + 1);
}

void	check_exit(char **map)
{
	t_num	x;

	init(&x);
	while (map[x.i])
	{
		x.j = 0;
		while (map[x.i][x.j])
		{
			if (map[x.i][x.j] == 'C'
			|| map[x.i][x.j] == 'P')
				(ft_printf("Error\nPath Not Valid!\n"), exit(-1));
			x.j++;
		}
		x.i++;
	}
}

void	norm_mov(t_long **p)
{
	(*p)->pi = -1;
	(*p)->pj = 0;
}
