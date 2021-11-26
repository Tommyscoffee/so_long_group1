#include "so_long.h"
void	move_up(t_vars *vars)
{
	char	next;

	next = vars->map[vars->chara_y - 1][vars->chara_x];
	if (next == '1' )
		return ;
	else
	{
		if (next == 'C')
			get_coin(vars);
		if (next == 'E')
			ft_exit(vars);
		else
		{
			vars->map[vars->chara_y][vars->chara_x] = '0';
			vars->map[--vars->chara_y][vars->chara_x] = 'P';
			add_move_cnt(vars);
		}
	}
	return ;
}

void	move_left(t_vars *vars)
{
	char	next;

	next = vars->map[vars-> chara_y][vars-> chara_x - 1];
	if (next == '1')
		return ;
	else
	{
		if (next == 'C')
			get_coin(vars);
		if (next == 'E')
			ft_exit(vars);
		else
		{
			vars->map[vars->chara_y][vars->chara_x] = '0';
			vars->map[vars->chara_y][--vars->chara_x] = 'P';
			add_move_cnt(vars);
		}
	}
	return ;
}

void	move_down(t_vars *vars)
{
	char	next;

	next = vars->map[vars->chara_y + 1][vars->chara_x];
	if (vars->map[vars->chara_y + 1][vars->chara_x] == '1')
		return ;
	else
	{
		if (next == 'C')
			get_coin(vars);
		if (next == 'E')
			ft_exit(vars);
		else
		{
			vars->map[vars->chara_y][vars->chara_x] = '0';
			vars->map[++vars->chara_y][vars->chara_x] = 'P';
			add_move_cnt(vars);
		}
	}
	return ;
}

void	move_right(t_vars *vars)
{
	char	next;

	next = vars->map[vars->chara_y][vars->chara_x + 1];
	if (next == '1')
		return ;
	else
	{
		if (next == 'C')
			get_coin(vars);
		if (next == 'E')
			ft_exit(vars);
		else
		{
			vars->map[vars->chara_y][vars->chara_x] = '0';
			vars->map[vars->chara_y][++vars->chara_x] = 'P';
			add_move_cnt(vars);
		}
	}
	return ;
}
