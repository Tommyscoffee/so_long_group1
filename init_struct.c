#include "so_long.h"

void	init_array(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		vars->Eflag[i++] = 0;
	}
	return ;
}

void	init_struct(t_vars *vars)
{
	vars->coin_num = 0;
	vars->coin_get = 0;
	vars->exit_flag = 0;
	vars->move_cnt = 0;
	init_array(vars);
	return ;
}

void	init_mlx(t_vars *vars)
{
	int	*V_W;
	int	*V_H;
	int	MW;
	int	MH;

	V_W = &vars->width;
	V_H = &vars->height;
	MW = vars->map_width;
	MH = vars->map_height;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, MW * 32, MH * 32, "so_long");
	vars->img = mlx_new_image(vars->mlx, 32, 32);
	vars->chara = mlx_xpm_file_to_image(vars->mlx, CHARA, V_W, V_H);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, FLOOR, V_W, V_H);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, COIN, V_W, V_H);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, WALL, V_W, V_H);
	vars->rock = mlx_xpm_file_to_image(vars->mlx, ROCK, V_W, V_H);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, EXIT, V_W, V_H);
}
