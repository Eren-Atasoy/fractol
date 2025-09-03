NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

CFILES = \
    main.c \

OFILES = $(CFILES:.c=.o)

MLX_DIR = minilibx-linux
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OFILES) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	make clean -C $(MLX_DIR)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

