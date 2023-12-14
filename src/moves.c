/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:46:19 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/14 14:36:01 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	update_move(t_all *all, int row, int col)
{
	if (all->map[row][col] == '0')
	{
		all->map[row][col] = 'P';
		all->pos_x = col;
		all->pos_y = row;
	}
	if (all->map[row][col] == 'E')
	{
		if(all->lcoin != all->score)
			return (0);
	}
	return (1);
}

static int	w_s_controls(int key, t_all *all)
{
	int	row;
	int	col;
	int	k;

	col = all->pos_x;
	row = all->pos_y;
	if (key == XK_w)
	{
		row--;
		if (all->map[row][col] == '1')
			return (0);
		k = update_move(all, row, col);
		if (!k)
			return (0);
		all->map[row + 1][col] = '0';
	}
	if (key == XK_s)
	{
		row++;
		if (all->map[row][col] == '1')
			return (0);
		k = update_move(all, row, col);
		if (!k)
			return (0);
		all->map[row - 1][col] = '0';
	}
	return (1);
}

static int	a_d_controls(int key, t_all *all)
{
	int	row;
	int	col;
	int	k;

	col = all->pos_x;
	row = all->pos_y;
	if (key == XK_a)
	{
		col--;
		if(all->map[row][col] == '1')
			return (0);
		k = update_move(all, row, col);
		if (!k)
			return (0);
		all->map[row][col + 1] = '0';
	}
	if (key == XK_d)
	{
		col++;
		if (all->map[row][col] == '1')
			return (0);
		k = update_move(all, row, col);
		if (!k)
			return (0);
		all->map[row][col - 1] = '0';
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
	return (1);
}
