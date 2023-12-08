/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:46:19 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/08 20:57:38 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	update_move(t_player *move, t_layout *layout, int row, int col)
{
	if (layout->map[row][col] == '0')
	{
		layout->map[row][col] = 'P';
		move->pos_x = col;
		move->pos_y = row;
	}
	return (1);
}

static int	w_s_controls(int key, t_player *move, t_layout *layout)
{
	int	row;
	int	col;
	int	k;

	col = move->pos_x;
	row = move->pos_y;
	if (key == 115)
	{
		row--;
		//if (layout->map[row][col] == '1')
			//return (0);
		k = update_move(move, layout, row, col);
		//if (!k)
			//return (0);
		layout->map[row + 1][col] = '0';
	}
	else if (key == 119)
	{
		row++;
		//if (layout->map[row][col] == '1')
			//return (0);
		k = update_move(move, layout, row, col);
		//if (!k)
			//return (0);
		layout->map[row - 1][col] = '0';
	}
	return (1);
}

static int	a_d_controls(t_player *move)
{
	return (1);
}

int	compute_move(int key, t_data *data, t_layout *layout, t_player *move, t_graphics *graph, t_score *score)
{
	int	com;

	if (key == 119)
		com = w_s_controls(key, move, layout);
	if (key == 115)
		com = w_s_controls(key, move, layout);
	if (com)
		adding_graphics(data, layout, graph, move, score);
	return (1);
}
