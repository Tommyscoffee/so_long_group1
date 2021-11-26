#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "minilibx_remote/mlx.h"
# include "GNL/get_next_line.h"
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define FLOOR "./img/Floor.xpm"
# define CHARA "./img/human_2.xpm"
# define COIN "./img/coin_floor.xpm"
# define WALL "./img/wall_rock.xpm"
# define ROCK "./img/stop_rock.xpm"
# define EXIT "./img/exit.xpm"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*img;
	void	*floor;
	void	*chara;
	void	*coin;
	void	*wall;
	void	*rock;
	void	*exit;
	int		*data;
	int		width;
	int		height;
	int		win_width;
	int		win_height;
	int		chara_x;
	int		chara_y;
	int		floor_x;
	int		floor_y;
	int		rock_x;
	int		rock_y;
	int		coin_x;
	int		coin_y;
	int		exit_x;
	int		exit_y;
	int		coin_num;
	int		coin_get;
	char	**map;
	int		map_width;
	int		map_height;
	int		size_l;
	int		bpp;
	int		endian;
	int		exit_flag;
	int		move_cnt;
	int		Eflag[3];
	int		*line_check;
}		t_vars;

int		ft_strcmp(const char *s1, const char *s2);
void	init_array(t_vars *vars);
void	init_struct(t_vars *vars);
void	init_mlx(t_vars *vars);
void	put_wall(t_vars *vars, int y, int x);
void	put_floor(t_vars *vars, int y, int x);
void	put_rock(t_vars *vars, int i, int l);
void	put_coin(t_vars *vars, int coin_y, int coinxs_x);
void	put_character(t_vars *vars, int y, int x);
void	put_exit(t_vars *vars, int y, int x);
void	move_up(t_vars *vars);
void	move_left(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	initmap(t_vars *vars);
void	check_map(t_vars *vars);
void	put_error(char *s);
int		move_character(t_vars *vars);
int		exchange_chara_to_floor(t_vars *vars);
void	get_coin(t_vars *vars);
void	ft_exit(t_vars *vars);
void	add_move_cnt(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		rendermap(t_vars *vars, int x, int y);
void	check_extension(char *map_file);
int		main(int argc, char **argv);
void	rect_check(t_vars *vars, int line_num, int line_len);
int		destroy_win(t_vars *vars);
int		get_line(t_vars *vars, int fd, int i, const char *argv);
int		store_line(t_vars *vars, char *line, int i, const char *argv);
void	init_item(t_vars *vars, int x, int y);
void	P_C_E_put(t_vars *vars, int y, int x);
int		remap(t_vars *vars);
char	*ft_strrchr(const char *s, int c);
#endif