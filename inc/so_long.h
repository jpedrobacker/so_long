/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:27:48 by jbergfel          #+#    #+#             */
/*   Updated: 2024/02/21 14:22:27 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../lib/libftprintf/ft_printf.h"
# include "../lib/libftprintf/libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define MLX_ERROR		0
# define MALLOC_ERROR	1
# define WIDTH			64
# define HEIGHT			64
# define SIDE_LEN		800
typedef struct s_all
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**temp_map;
	char	**path;
	int		map_error;
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
	int		current_level;
	int		fd;
	int		start;
	void	*player;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*menu;
}	t_all;

int		read_map(t_all *all, char *arr);
void	graphics_env(t_all *all);
void	adding_graphics(t_all *all);
int		compute_move(int key, t_all *all);
void	check_map_errors(t_all *all);
int		to_free(t_all *all);
void	arr_free(t_all *all, char **arr);

#endif
