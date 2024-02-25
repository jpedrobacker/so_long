NAME = so_long
INCLUDES = -I/usr/include -Imlx
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
MLXCLONE = git clone git@github.com:42Paris/minilibx-linux.git
MLX_LIB = lib/minilibx-linux
LIB = src/libftprintf.a
MLX = src/libmlx.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) src/so_long.c src/map.c src/graphics.c src/moves.c src/error.c src/free.c $(LIB) $(MLX_FLAGS) -o $(NAME)

play:
	./so_long "tests/map1.ber"

check:
	ifneq $(MLX_LIB)
		echo "ok"
	else
		cd lib && git clone git@github.com:42Paris/minilibx-linux.git
	endif

mlib:	check
		make -C lib/libftprintf
		make clean -C lib/libftprintf
		mv lib/libftprintf/libftprintf.a src
		make -C lib/minilibx-linux
		mv lib/minilibx-linux/libmlx.a src

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -rf $(LIB) $(MLX)
fclean:

re:
