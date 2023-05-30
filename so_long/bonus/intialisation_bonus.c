/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialisation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:39:10 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/30 18:58:19 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init(t_num *x)
{
	x->c = 0;
	x->e = 0;
	x->p = 0;
	x->j = 0;
	x->i = 0;
}

void	init2(t_dir *x, size_t im, size_t jm)
{
	x->x = 0;
	x->y = 0;
	x->xm = im;
	x->ym = jm - 1;
}

void	init3(t_pos	*x)
{
	x->x = 0;
	x->y = 0;
}

t_pos	get_pos(char **map, char c)
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
			if (map[i][j] == c)
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

void	check_name(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i--;
	if (av[i] != 'r' || av[i - 1] != 'e'
		|| av[i - 2] != 'b' || av[i - 3] != '.')
		(ft_printf("Error\nName not Valid!\n"), exit (-1));
}
