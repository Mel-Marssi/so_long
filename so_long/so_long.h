/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:22:22 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/21 16:39:56 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"

typedef struct s_num
{
	int		p;
	int		e;
	int		c;
	int		j;
	size_t	i;
}		t_num;
typedef struct s_dir
{
	int	x;
	int	y;
	int	xm;
	int	ym;
}		t_dir;
void	init(t_num *x);
void	init2(t_dir *x, size_t im, size_t jm);
void	ft_count(t_num x);
void	check_char_map(char **map, size_t size, size_t im);
int		strlen_dbl(char	*av);
char	**get_map(char *av, size_t size);
void	check_map(char *av);
void	check_wall(char **map, t_dir x);
#endif
