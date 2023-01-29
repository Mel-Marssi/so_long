/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:22:22 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/29 16:37:58 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

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
typedef struct s_pos
{
	int			x;
	int			y;
}		t_pos;

typedef struct s_long
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	int		wth;
	int		hgt;
	int		i;
	int		j;
	int 	pi;
	int		pj;
	int		c;
}			t_long;

void	init(t_num *x);
void	init2(t_dir *x, size_t im, size_t jm);
void	init3(t_pos	*x);
void	ft_count(t_num x);
void	check_char_map(char **map, size_t size, size_t im);
int		strlen_dbl(char	*av);
char	**get_map(char *av, size_t size);
void	check_map(char *av);
void	check_wall(char **map, t_dir x);
t_pos	get_pos(char **map);
void	flod_fill(char **map, int i, int j);
void	check_path(char **map);
void	ft_protect(void *ptr);
void	init_mlx(char	**map, char *av, t_long *p);
void	put_image(t_long p, char *str);
void	put_map(char **map, t_long p);
#endif
