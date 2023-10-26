#include "so_long.h"

void	add_move_cnt(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->move_cnt++;
	printf("count = %d\n", vars->move_cnt);
	rendermap(vars, x, y);
	return ;
}

void	get_coin(t_vars *vars)
{
	vars->coin_get++;
	if (vars->coin_get == vars->coin_num)
		vars->exit_flag = 1;
	return ;
}
