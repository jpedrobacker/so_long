/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:46:19 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/30 11:21:06 by jbergfel         ###   ########.fr       */
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
	if (all->map[row][col] == 'C')
	{
		all->map[row][col] = 'P';
		all->pos_x = col;
		all->pos_y = row;
		all->score++;
		if (all->score == all->to_score)
		{
			all->can_finish = 1;
		}
	}
	if (all->map[row][col] == 'E')
	{
		if (all->can_finish == 1)
		{
			all->current_level;
			mlx_destroy_display(all->mlx_ptr);
			init_game();
		}
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
	int	i;
	int	j;
	int	k;

	col = all->pos_x;
	row = all->pos_y;
	if (key == XK_a)
	{
		all->player = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/outlaw_backwards.xpm", &i, &j);
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
		all->player = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/outlaw_foward.xpm", &i, &j);
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

	all->score = 0;
	if (key == XK_w || key == XK_s)
		com = w_s_controls(key, all);
	if (key == XK_a || key == XK_d)
		com = a_d_controls(key, all);
	if (com)
		adding_graphics(all);
	return (1);
}
