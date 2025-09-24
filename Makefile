NAME = fractol
BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

CFILES = \
	main.c \
	color.c \
	init.c \
	render.c \
	ft_atof.c \
	error.c \
	event.c \
	utils.c \

BFILES = \
	bonus/main_bonus.c \
	bonus/color_bonus.c \
	bonus/init_bonus.c \
	bonus/render_bonus.c \
	bonus/ft_atof_bonus.c \
	bonus/error_bonus.c \
	bonus/event_bonus.c \
	bonus/utils_bonus.c \


OFILES = $(CFILES:.c=.o)
BOFILES =  $(BFILES:.c=.o)

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz



all: $(NAME)


$(NAME): $(OFILES)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OFILES) $(MLX_FLAGS) -o $(NAME)

bonus: $(BOFILES)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(BOFILES) $(MLX_FLAGS) -o $(BONUS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OFILES) $(BOFILES)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re

