INCLUDES = -I/usr/include -Imlx
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
MLXDIR = ./minilibx-linux
MLX_LIB = $(MLXDIR)/libmlx_$(UNAME).a
LIB = libft.a

run:
	cd src && $(CC) so_long.c map.c graphics.c moves.c error.c free.c $(LIB) $(MLX_FLAGS) && ./a.out "../tests/map1.ber"
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
		make -C $(MLXDIR)
