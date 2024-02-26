NAME = so_long
INCLUDES = -I/usr/include -Imlx
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
MLXCLONE = git clone git@github.com:42Paris/minilibx-linux.git
MLX_LIB = lib/minilibx-linux
LIB = libftprintf.a
MLX = libmlx.a

all: $(NAME)

$(NAME):
	cd src && $(CC) $(CFLAGS) so_long.c map.c graphics.c moves.c error.c free.c $(LIB) $(MLX_FLAGS) -o $(NAME)

play:
	cd src && ./so_long "../maps/map0.ber"

check:
	ifneq ($(MLX_LIB), )
		echo "ok"
	else
		cd lib && git clone git@github.com:42Paris/minilibx-linux.git
	endif

mlib:
	make -C lib/libftprintf
	make clean -C lib/libftprintf
	mv lib/libftprintf/libftprintf.a src
	make -C lib/minilibx-linux
	mv lib/minilibx-linux/libmlx.a src

clean:
	rm -rf $(LIB) $(MLX)

fclean:

re:
