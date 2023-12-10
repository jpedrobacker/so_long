/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:27:48 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/09 22:01:38 by jbergfel         ###   ########.fr       */
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

typedef struct s_graphics
{
	void	*floor;
	void	*wall;
	void	*exit;
}	t_graphics;

typedef struct s_score
{
	void	*coin;
	int		score;
} t_score;


typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	void	*player;
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


void	init_game(void);
int		read_map(t_layout *layout, char **arr);
void	graphics_env(t_data *data, t_graphics *graphics, t_player *player, t_score *score);
void	adding_graphics(t_data *data ,t_layout *layout, t_graphics *graphics, t_player *player, t_score *score);
int		compute_move(int key, t_data *data, t_layout *layout, t_player *player, t_graphics *graph, t_score *score);
int		exit_point(t_data *data, t_layout *layout);
#endif
