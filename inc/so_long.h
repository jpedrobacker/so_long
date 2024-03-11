/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:27:48 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/11 13:37:17 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
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
void	graphics_env(t_all *all);
void	adding_graphics(t_all *all);
int		compute_move(int key, t_all *all);
void	check_map_errors(t_all *all);
int		to_free(t_all *all);
int		check_elems(t_all *all);
void	check_walls(t_all *all, char **temp_map);
void	count_elems(t_all *all, char **temp_map);

#endif
