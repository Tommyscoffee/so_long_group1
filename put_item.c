#include "so_long.h"

void	put_wall(t_vars *vars, int y, int x)
{
	int	VW;
	int	VH;

	VW = vars->width;
	VH = vars->height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, VW * x, VH * y);
	return ;
}

void	put_floor(t_vars *vars, int y, int x)
{
	int	VW;
	int	VH;

	VW = vars->width;
	VH = vars->height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, VW * x, VH * y);
	return ;
}

void	put_coin(t_vars *vars, int y, int x)
{
	int	VW;
	int	VH;

	vars->coin_x = x;
	vars->coin_y = y;
	VW = vars->width;
	VH = vars->height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->coin, VW * x, VH * y);
	return ;
}

void	put_character(t_vars *vars, int y, int x)
{
	int	VW;
	int	VH;

	vars->chara_x = x;
	vars->chara_y = y;
	VW = vars->width;
	VH = vars->height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->chara, VW * x, VH * y);
	return ;
}

void	put_exit(t_vars *vars, int y, int x)
{
	int	VW;
	int	VH;

	vars->exit_x = x;
	vars->exit_y = y;
	VW = vars->width;
	VH = vars->height;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, VW * x, VH * y);
	return ;
}
