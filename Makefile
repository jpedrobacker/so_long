NAME = so_long
CC = cc
SRC_DIR = src/
FIND = $(shell find $(SRC_DIR))
SRC = $(filter %.c, $(FIND))
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lXext -lX11
MLXCLONE = git clone git@github.com:42Paris/minilibx-linux.git
MLXLIB = lib/mlx
LIB = src/libftprintf.a
MLX = src/libmlx.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIB) $(MLX) $(MLX_FLAGS) -o $(NAME)
	mv ./so_long src/

play:
	cd src && ./so_long "../maps/map1.ber"

mlx:
	cd lib && $(MLXCLONE) mlx

mlib:
	make -C lib/libftprintf
	make clean -C lib/libftprintf
	mv lib/libftprintf/libftprintf.a src
	make -C lib/mlx
	mv lib/mlx/libmlx.a src

clean:
	rm -rf $(LIB) $(MLX)

fclean: clean
		make fclean -C lib/libftprintf
		make clean -C lib/mlx

re: fclean mlib all

