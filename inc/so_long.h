/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:27:48 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/02 11:43:11 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libftprintf/ft_printf.h"
# include "../lib/libftprintf/libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define WIDTH			64
# define HEIGHT			64

typedef struct s_all
{
	int		map_error;
	int		moves;
	int		row;
	int		col;
	int		lplayer;
	int		lexit;
	int		pos_x;
	int		pos_y;
	int		score;
	int		to_score;
	int		score_ok;
	int		can_finish;
	int		finish;
	int		fd;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_all;

int		read_map(t_all *all, char *arr);
int		compute_move(int key, t_all *all);
int		w_key(t_all *all, int col, int row);
int		s_key(t_all *all, int col, int row);
int		a_key(t_all *all, int col, int row);
int		d_key(t_all *all, int col, int row);
int		to_free(t_all *all);
int		to_free_incomplete(t_all *all);
int		update_move(t_all *all, int row, int col);
int		is_ok(t_all *all);
void	adding_graphics(t_all *all);
void	check_map_errors(t_all *all);
void	graphics_env(t_all *all);
void	to_free_game(t_all *all);
void	to_free_game_map(t_all *all);
void	check_elems(t_all *all);
void	check_walls(t_all *all);
void	count_elems(t_all *all);

#endif
