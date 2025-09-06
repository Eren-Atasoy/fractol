NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ilibft

CFILES = \
	main.c

OFILES = $(CFILES:.c=.o)

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)


$(NAME): $(LIBFT) $(OFILES)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(MLX_FLAGS) -o $(NAME)


$(LIBFT):
	make -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OFILES)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

