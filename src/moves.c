/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:46:19 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/02 10:49:59 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_finish(t_all *all)
{
	if (all->finish == 1)
	{
		ft_printf("moves: %d\n", ++all->moves);
		to_free(all);
	}
}

int	update_move(t_all *all, int row, int col)
{
	if (all->map[row][col] == '0')
	{
		ft_printf("moves: %d\n", ++all->moves);
		all->map[row][col] = 'P';
		all->pos_x = col;
		all->pos_y = row;
	}
	if (all->map[row][col] == 'C')
	{
		ft_printf("moves: %d\n", ++all->moves);
		all->map[row][col] = 'P';
		all->pos_x = col;
		all->pos_y = row;
		all->score++;
		if (all->score == all->to_score)
			all->finish = 1;
	}
	if (all->map[row][col] == 'E')
	{
		check_finish(all);
		return (0);
	}
	return (1);
}

static int	w_s_controls(int key, t_all *all)
{
	int	row;
	int	col;

	col = all->pos_x;
	row = all->pos_y;
	if (key == XK_w)
		w_key(all, col, row);
	if (key == XK_s)
	{
		s_key(all, col, row);
	}
	return (1);
}

static int	a_d_controls(int key, t_all *all)
{
	int	row;
	int	col;

	col = all->pos_x;
	row = all->pos_y;
	if (key == XK_a)
	{
		a_key(all, col, row);
	}
	if (key == XK_d)
	{
		d_key(all, col, row);
	}
	return (1);
}

int	compute_move(int key, t_all *all)
{
	int	com;

	if (key == XK_w || key == XK_s)
		com = w_s_controls(key, all);
	if (key == XK_a || key == XK_d)
		com = a_d_controls(key, all);
	if (com)
		adding_graphics(all);
	if (key == 65307)
		to_free(all);
	return (1);
}
