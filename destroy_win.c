#include "so_long.h"

int	destroy_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
