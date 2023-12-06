/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:27:48 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/05 13:54:15 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


# define MLX_ERROR		0
# define MALLOC_ERROR	1
# define WIDTH			600
# define HEIGHT			600
# define SIDE_LEN		800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_mov
{
	int	x;
	int	y;
}	t_mov;

typedef struct s_layout
{
	int	row;
	int	col;
	int	exit;
	int	coin;
	int	player;
}	t_layout;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_mov	pos;
}	t_data;



void	init_game(void);
void	*spawn_player(void *ptr);
int		player_events(int keycode, t_data *data);
t_layout	new_layout(void);
char	**print_map(char *path);

#endif
