INCLUDES = -I/usr/include -Imlx
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLXDIR = ./mlx
MLX_LIB = $(MLXDIR)/libmlx_$(UNAME).a

run:
	$(CC) so_long.c $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
		make -C $(MLXDIR)
