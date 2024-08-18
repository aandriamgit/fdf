CC = cc
OBJ = $(SRC:.c=.o)
NAME = fdf
CFLAGS = -Wall -Wextra -Werror
MINILIBX = ./minilibx/libmlx_Linux.a
SRC = fdf.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./lib/ft_atoi.c \
			./lib/ft_split.c \
			./lib/ft_strlen.c \
			./lib/ft_substr.c \
			./lib/ft_isdigit.c \
			./arg_check/arg_check.c \
			./vars_init/vars_init.c \
			./map_init/map_init.c \
			./map_init/color_init.c \
			./map_init/map_xyz_init.c \
			./map_init/extract_color.c \
			./hook_functions/close_window.c \
			./hook_functions/key_hooks.c \
			./hook_functions/scale_hook.c \
			./draw_map/draw_map.c \
			./draw_map/draw_line.c \
			./draw_map/color_gradient.c \

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) -L./minilibx/ -lmlx_Linux -lX11 -lXext -lm -lz -o $(NAME) -g

$(MINILIBX):
	make -C minilibx all

clean:
	make -C minilibx clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
