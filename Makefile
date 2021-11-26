NAME = so_long
SRCS = check_funcs.c \
	count.c \
	destroy_win.c \
	init_struct.c \
	initmap.c \
	move_chara.c \
	put_error.c \
	put_item.c \
	so_long_utils.c \
	so_long.c \

MAKE = make


MLX_LIB = ./minilibx_remote/libmlx.a

MLX_DIR = ./minilibx_remote

GNL = ./GNL/get_next_line.c \
	./GNL/get_next_line_utils.c

OPT = -L/usr/X11R6/lib  -Imlx -lX11 -lXext -framework OpenGL -framework AppKit 

HEADER = so_long.h

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc

all : $(NAME)

$(NAME):$(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(GNL) $(OPT) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	
clean :
	rm -f $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)

re : fclean all

.PHONY : all clean fclean re