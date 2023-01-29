/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:08:26 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/28 21:08:47 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(char	**map, char *av, t_long *p)
{
	t_dir	x;

	init2(&x, strlen_dbl(av), ft_strlen(map[0]));
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

void	put_map(char **map, t_long p)
{
	while (map[p.i])
	{
		p.j = 0;
		while (map[p.i][p.j])
		{
			p.img = mlx_xpm_file_to_image(p.mlx, "textures/1.xpm",
					&p.hgt, &p.wth);
			ft_protect(p.img);
			mlx_put_image_to_window(p.mlx, p.win, p.img, p.j * 60, p.i * 60);
			if (map[p.i][p.j] =='1' )
				put_image(p, "textures/01.xpm");
			else if (map[p.i][p.j] == '0')
				put_image(p, "textures/1.xpm");
			else if (map[p.i][p.j] == 'P')
				put_image(p, "textures/P.xpm");
			else if (map[p.i][p.j] == 'C')
				put_image(p, "textures/C.xpm");
			else if (map[p.i][p.j] == 'E')
				put_image(p, "textures/E.xpm");
			p.j++;
		}
		p.i++;
	}
}
