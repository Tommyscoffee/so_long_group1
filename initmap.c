#include "so_long.h"

void	initmap(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		init_item(vars, x, y);
		y++;
	}
	check_map(vars);
	return ;
}

void	init_item(t_vars *vars, int x, int y)
{
	while (x < vars->map_width)
	{
		if (vars->map[y][x] == '1')
			put_wall(vars, y, x);
		else if (vars->map[y][x] == '0')
			put_floor(vars, y, x);
		else
			P_C_E_put(vars, y, x);
		x++;
	}
}

void	P_C_E_put(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'P')
	{
		put_character(vars, y, x);
		vars->Eflag[0]++;
	}
	else if (vars->map[y][x] == 'C')
	{
		vars->coin_num++;
		put_coin(vars, y, x);
		vars->Eflag[1]++;
	}
	else if (vars->map[y][x] == 'E')
	{
		put_exit(vars, y, x);
		vars->Eflag[2]++;
	}
	else
		put_error("unknown obejct detected\n");
}

int	get_line(t_vars *vars, int fd, int i, const char *argv)
{
	char	*line;
	int		d;

	d = 1;
	while (d == 1)
	{
		d = get_next_line(fd, &line);
		free(line);
		i++;
	}
	close(fd);
	vars->map = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	return (store_line(vars, line, i, argv));
}

int	store_line(t_vars *vars, char *line, int i, const char *argv)
{
	int	fd;
	int	d;
	int	line_len;

	fd = open(argv, O_RDONLY);
	d = 1;
	while (d == 1)
	{
		d = get_next_line(fd, &line);
		vars->map[i] = line;
		if (i == 0)
			line_len = ft_strlen(line);
		i++;
	}
	rect_check (vars, i, line_len);
	return (i);
}
