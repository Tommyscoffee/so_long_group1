#include "so_long.h"

void	check_map(t_vars *vars)
{
	if (vars->Eflag[0] == 0)
	{
		put_error("map has no character\n");
	}
	else if (vars->Eflag[0] > 1)
		put_error("map has mult character\n");
	if (vars->Eflag[1] == 0)
		put_error("map has no coin\n");
	if (vars->Eflag[2] == 0)
		put_error("map has no exit\n");
	return ;
}

void	check_extension(char *map_file)
{
	char	*extension;

	extension = ft_strrchr(map_file, '.');
	if (!extension || ft_strcmp(extension, ".ber"))
		put_error("invalid map file\n");
	return ;
}

void	rect_check(t_vars *vars, int row_num, int line_len)
{
	int	n;
	int	i;

	i = -1;
	n = -1;
	if (row_num == 1 && line_len == 0)
		put_error("map is completely empty\n");
	while (++i < row_num)
		if (!(vars->map[i][0] == '1' && vars->map[i][line_len - 1] == '1'))
			put_error("map is not surrounded by rectangle wall\n");
	while (++n < line_len)
		if (!(vars->map[0][n] == '1' && vars->map[row_num - 1][n] == '1'))
			put_error("map is not surrounded by rectangle wall\n");
	return ;
}
