/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:25:06 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/29 18:51:13 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_old(t_long *p, t_pos x, char *str)
{
	p->img = mlx_xpm_file_to_image(p->mlx, str, &p->hgt, &p->wth);
	ft_protect(p->img);
	mlx_put_image_to_window(p->mlx, p->win, p->img, x.y * 60, x.x * 60);
	if (p->map[x.x + p->pi][x.y + p->pj] == 'C')
	{
		p->img = mlx_xpm_file_to_image(p->mlx,
				"textures/1.xpm", &p->hgt, &p->wth);
		ft_protect(p->img);
		mlx_put_image_to_window(p->mlx, p->win, p->img,
			(x.y + p->pj) * 60, (x.x + p->pi) * 60);
	}
}

void	put_image_new(t_long *p, t_pos x, char *str)
{
	p->img = mlx_xpm_file_to_image(p->mlx, str, &p->hgt, &p->wth);
	ft_protect(p->img);
	mlx_put_image_to_window(p->mlx, p->win, p->img,
		(x.y + p->pj) * 60, (x.x + p->pi) * 60);
	p->map[x.x][x.y] = '0';
	p->map[x.x + p->pi][x.y + p->pj] = 'P';
}

void	norm_moves(t_long *p, t_pos x, char *str, int *move)
{
	put_image_old(p, x, "textures/1.xpm");
	put_image_new(p, x, str);
	(*move)++;
	ft_printf("move: %i\n", *move);
}

void	put_well(int keycode, t_long *p, t_pos x)
{
	static int	move;

	if (keycode == 13)
		norm_moves(p, x, "textures/PU.xpm", &move);
	else if (keycode == 1)
		norm_moves(p, x, "textures/PD.xpm", &move);
	else if (keycode == 2)
		norm_moves(p, x, "textures/Pr.xpm", &move);
	else if (keycode == 0)
		norm_moves(p, x, "textures/PL.xpm", &move);
}

int	check_move(t_long *p, t_pos x)
{
	if (x.x + p->pi <= 0 || x.y + p->pj <= 0
		|| x.x + p->pi >= ft_dstrlen(p->map)
		|| x.y + p->pj >= (int )ft_strlen(p->map[0]))
		return (1);
	if (p->map[x.x + p->pi][x.y + p->pj] == '1')
		return (1);
	return (0);
}
