/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workshop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mars < mel-mars@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:04:10 by mel-mars          #+#    #+#             */
/*   Updated: 2023/01/31 13:39:05 by mel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_long	p;

	if (ac <= 1)
		exit(-1);
	check_name(av[1]);
	p.map = get_map(av[1], strlen_dbl(av[1]));
	p.c = collect(p.map);
	check_map(av[1]);
	p.mlx = mlx_init();
	if (p.mlx == NULL)
		(ft_printf("Error\nMlx Failed!\n"), exit(-1));
	init_mlx(av[1], &p);
	if (p.wth * 60 > 5120 || p.hgt * 60 > 2880)
		(ft_printf("Error\nOut of screen!"), exit(-1));
	p.win = mlx_new_window(p.mlx, p.wth * 60, p.hgt * 60, "so_long");
	if (!p.win)
		(ft_printf("Error\nWindows Failed!\n"), exit(-1));
	put_map(p);
	mlx_string_put(p.mlx, p.win, 0, 0, 0x00FFFF, "MOVES:");
	mlx_hook(p.win, 2, 0, key_hook, &p);
	mlx_hook(p.win, 17, 0, ft_exit, &p);
	mlx_loop(p.mlx);
}
