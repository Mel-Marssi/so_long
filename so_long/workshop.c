/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workshop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:04:10 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/29 16:40:57 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_dstrlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int collect(char **map)
{
	int i;
	int	j;
	int c;

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

void	make_move(t_long *p)
{
	t_pos		x;
	static int	c;

	x = get_pos(p->map);
	if (x.x + p->pi <= 0 || x.y + p->pj <= 0 ||
		x.x + p->pi >= ft_dstrlen(p->map) ||
		x.y + p->pj >= (int )ft_strlen(p->map[0]))
		return ;
	if (p->map[x.x + p->pi][x.y + p->pj] == '1')
		return ;
	if (p->map[x.x + p->pi][x.y + p->pj] == 'C')
		c++;
	if (p->map[x.x + p->pi][x.y + p->pj] == 'E' && c == p->c)
		exit(0);
	else if (p->map[x.x + p->pi][x.y + p->pj] == 'E' && c != p->c)
		return ;
	p->img = mlx_xpm_file_to_image(p->mlx, "textures/1.xpm", &p->hgt, &p->wth);
	ft_protect(p->img);
	mlx_put_image_to_window(p->mlx, p->win, p->img, x.y * 60, x.x * 60);
	p->img = mlx_xpm_file_to_image(p->mlx, "textures/P.xpm", &p->hgt, &p->wth);
	ft_protect(p->img);
	mlx_put_image_to_window(p->mlx, p->win, p->img,
		(x.y + p->pj) * 60, (x.x + p->pi) * 60);
	p->map[x.x][x.y] = '0';
	p->map[x.x + p->pi][x.y + p->pj] = 'P';
}

int	key_hook(int keycode, t_long *p)
{
	if (keycode == 13)
	{
		p->pi = -1;
		p->pj = 0;
		make_move(p);
	}
	else if (keycode == 1)
	{
		p->pi = 1;
		p->pj = 0;
		make_move(p);
	}
	else if (keycode == 2)
	{
		p->pi = 0;
		p->pj = 1;
		make_move(p);
	}
	else if (keycode == 0)
	{
		p->pi = 0;
		p->pj = -1;
		make_move(p);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_long	p;
	char 	**map;

	if (ac <= 1)
		exit(-1);
	map = get_map(av[1], strlen_dbl(av[1]));
	p.map = map;
	p.c = collect(map);
	check_map(av[1]);
	p.mlx = mlx_init();
	init_mlx(map, av[1], &p);
	p.win = mlx_new_window(p.mlx, p.wth * 60, p.hgt * 60, "so_long");
	put_map(map, p);
	mlx_hook(p.win,2, 0, key_hook, &p);
	mlx_loop(p.mlx);
}
