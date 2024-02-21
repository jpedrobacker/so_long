NAME = so_long
INCLUDES = -I/usr/include -Imlx
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
MLXDIR = ./minilibx-linux
MLX_LIB = $(MLXDIR)/libmlx_$(UNAME).a
LIB = libftprintf.a

run:
	cd src && $(CC) $(CFLAGS) so_long.c map.c graphics.c moves.c error.c free.c $(LIB) $(MLX_FLAGS) -o $(NAME) && ./so_long "../tests/map1.ber"

makelib:
		make -C lib/libftprintf
		make clean -C lib/libftprintf
		mv lib/libftprintf/libftprintf.a src/
		make -C lib/minilibx-linux
		mv lib/minilibx-linux/libmlx.a src/libmlx.a

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:

fclean:

re:
