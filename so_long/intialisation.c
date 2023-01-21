/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:39:10 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/21 21:00:00 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
