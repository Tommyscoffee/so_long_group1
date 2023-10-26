/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:23:00 by atomizaw          #+#    #+#             */
/*   Updated: 2021/11/22 22:54:06 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_vars *vars)
{
	if (vars->exit_flag == 1)
	{
		add_move_cnt(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	else
		return ;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W)
		move_up(vars);
	else if (keycode == A)
		move_left(vars);
	else if (keycode == S)
		move_down(vars);
	else if (keycode == D)
		move_right(vars);
	return (0);
}

int	rendermap(t_vars *vars, int x, int y)
{
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			if (vars->map[y][x] == '1')
				put_wall(vars, y, x);
			else if (vars->map[y][x] == '0')
				put_floor(vars, y, x);
			else if (vars->map[y][x] == 'P')
				put_character(vars, y, x);
			else if (vars->map[y][x] == 'C')
				put_coin(vars, y, x);
			else if (vars->map[y][x] == 'E')
				put_exit(vars, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	remap(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	rendermap(vars, x, y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;
	int		i;

	if (argc != 2)
		put_error("map is nowhere to be found.\n");
	check_extension(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		put_error("failed to read map\n");
	i = 1;
	init_struct(&vars);
	vars.map_height = get_line(&vars, fd, i, argv[1]);
	vars.map_width = ft_strlen(vars.map[0]);
	init_mlx(&vars);
	initmap(&vars);
	mlx_hook(vars.win, 2, 1L << 0, &key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 15, &destroy_win, &vars);
	mlx_expose_hook(vars.win, &remap, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
