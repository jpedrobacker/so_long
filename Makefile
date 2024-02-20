INCLUDES = -I/usr/include -Imlx
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
MLXDIR = ./minilibx-linux
MLX_LIB = $(MLXDIR)/libmlx_$(UNAME).a
LIB = libftprintf.a

makelib:
		make -C lib/libftprintf
		make clean -C lib/libftprintf
		make -C lib/minilibx-linux
		mv lib/libftprintf/libftprintf.a src/
		mv lib/minilibx-linux/libmlx.a src/
run:
	cd src && $(CC) $(CFLAGS) so_long.c map.c graphics.c moves.c error.c free.c $(LIB) $(MLX_FLAGS) && ./a.out "../tests/map1.ber"
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:

fclean:

re:
