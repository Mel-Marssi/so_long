/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:26 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/30 16:32:17 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_mlx(char *av, t_long *p)
{
	t_dir	x;

	init2(&x, strlen_dbl(av), ft_strlen(p->map[0]));
	p->hgt = x.xm;
	p->wth = x.ym;
	p->i = 0;
	p->j = 0;
}

void	ft_protect(void *ptr)
{
	if (ptr == NULL)
		exit(-1);
	else
		return ;
}

void	put_image(t_long p, char *str)
{
	p.img = mlx_xpm_file_to_image(p.mlx, str, &p.hgt, &p.wth);
	ft_protect(p.img);
	mlx_put_image_to_window(p.mlx, p.win, p.img, p.j * 60, p.i * 60);
}

void	put_map(t_long p)
{
	while (p.map[p.i])
	{
		p.j = 0;
		while (p.map[p.i][p.j])
		{
			p.img = mlx_xpm_file_to_image(p.mlx, "textures/1.xpm",
					&p.hgt, &p.wth);
			ft_protect(p.img);
			mlx_put_image_to_window(p.mlx, p.win, p.img, p.j * 60, p.i * 60);
			if (p.map[p.i][p.j] == '1' )
				put_image(p, "textures/01.xpm");
			else if (p.map[p.i][p.j] == '0')
				put_image(p, "textures/1.xpm");
			else if (p.map[p.i][p.j] == 'P')
				put_image(p, "textures/PU.xpm");
			else if (p.map[p.i][p.j] == 'C')
				put_image(p, "textures/C.xpm");
			else if (p.map[p.i][p.j] == 'E')
				put_image(p, "textures/E.xpm");
			p.j++;
		}
		p.i++;
	}
}

void	make_move(t_long *p, int keycode)
{
	t_pos		x;
	t_long		ef;
	static int	c;

	x = get_pos(p->map, 'P');
	ef = *p;
	if (check_move(p, x) == 1)
		return ;
	if (p->map[x.x + p->pi][x.y + p->pj] == 'C')
		c++;
	if (c == p->c)
	{
		ef.i = get_pos(p->map, 'E').x;
		ef.j = get_pos(p->map, 'E').y;
		put_image(ef, "textures/1.xpm");
		put_image(ef, "textures/EF.xpm");
	}
	if (p->map[x.x + p->pi][x.y + p->pj] == 'E' && c == p->c)
		(ft_printf("You win!\nWelcome to the new universe!\n"), exit(0));
	else if (p->map[x.x + p->pi][x.y + p->pj] == 'E' && c != p->c)
		return ;
	put_well(keycode, p, x);
}
