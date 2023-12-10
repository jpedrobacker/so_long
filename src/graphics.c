/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:42:25 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/09 22:13:14 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	graphics_env(t_data *data, t_graphics *graphics, t_player *player, t_score *score)
{
	int	i;
	int	j;

	graphics->floor = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/floor.xpm", &i, &j);
	graphics->wall = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/poze-do-gordo.xpm", &i, &j);
	graphics->exit = mlx_xpm_file_to_image(data->mlx_ptr, "", &i, &j);
	score->coin = mlx_xpm_file_to_image(data->mlx_ptr, "", &i, &j);
	player->player = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/player.xpm", &i, &j);
}

static void	count_score(t_data *data, t_score *score, int row, int col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, score->coin, col *45, row *45);
	score->score++;
}

static void	spawn_player(t_data *data, t_player *player, int row, int col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player->player, col * 45, row *45);
	player->pos_x = col;
	player->pos_y = row;
}

void	adding_graphics(t_data *data ,t_layout *layout, t_graphics *graphics, t_player *player, t_score *score)
{
	int	row;
	int	col;

	row = 0;
	score->score = 0;
	while (row < layout->row)
	{
		col = 0;
		while (layout->map[row][col])
		{
			if (layout->map[row][col] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, graphics->wall, col * 45, row * 45);
			}
			/*if (layout->map[row][col] == 'C')
			{
				count_score(data, score, row, col);
			}*/
			if (layout->map[row][col] == 'P')
			{
				spawn_player(data, player, row, col);
			}
			if (layout->map[row][col] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, graphics->floor, col * 45, row * 45);
			}
			col++;
		}
		row++;
	}
}
