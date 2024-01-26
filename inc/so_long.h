/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:27:48 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/25 19:38:34 by jbergfel         ###   ########.fr       */
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
# define WIDTH			64
# define HEIGHT			64
# define SIDE_LEN		800

typedef struct s_graphics
{
	void	*floor;
	void	*wall;
	void	*exit;
}	t_graphics;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		score;
	void	*player;
	void	*coin;
}	t_player;

typedef struct s_layout
{
	char	**map;
	int		row;
	int		col;
	int		exit;
	int		coin;
	int		player;
	int		fd;
}	t_layout;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_all
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_error;
	int		row;
	int		col;
	int		lplayer;
	int		pos_x;
	int		pos_y;
	int		score;
	int		to_score;
	int		score_ok;
	int		can_finish;
	int		fd;
	int		start;
	void	*player;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*menu;
}	t_all;

void	init_game(int a);
int		start(int key, t_all *all);
int		read_map(t_all *all, char **arr);
void	graphics_env(t_all *all);
void	adding_graphics(t_all *all);
int		compute_move(int key, t_all *all);

#endif
