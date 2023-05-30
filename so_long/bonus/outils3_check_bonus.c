/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils3_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:36:04 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/30 20:35:08 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				(ft_printf("Error\nPath Not Valid!\n"), exit(-1));
			x.j++;
		}
		x.i++;
	}
}

int	key_hook(int keycode, t_long *p)
{
	if (keycode == 13)
		(norm_mov(&p), make_move(p, keycode));
	else if (keycode == 1)
	{
		p->pi = 1;
		p->pj = 0;
		make_move(p, keycode);
	}
	else if (keycode == 2)
	{
		p->pi = 0;
		p->pj = 1;
		make_move(p, keycode);
	}
	else if (keycode == 0)
	{
		p->pi = 0;
		p->pj = -1;
		make_move(p, keycode);
	}
	else if (keycode == 53)
		(mlx_destroy_window(p->mlx, p->win), exit(0));
	return (0);
}

int	ft_dstrlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	collect(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
