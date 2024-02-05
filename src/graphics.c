/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:42:25 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/31 11:38:01 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	graphics_env(t_all *all)
{
	int	row;
	int	col;

	all->floor = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/floor.xpm", &row, &col);
	all->wall = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/cactus.xpm", &row, &col);
	all->exit = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/horse.xpm", &row, &col);
	all->coin = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/carrot.xpm", &row, &col);
	all->player = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/outlaw_foward.xpm", &row, &col);
}

static void	count_score(t_all *all, int row, int col)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->coin, col * HEIGHT, row * WIDTH);
	all->to_score++;
}

static void	spawn_player(t_all *all, int row, int col)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->player, col * HEIGHT, row * WIDTH);
	all->pos_x = col;
	all->pos_y = row;
	all->lplayer++;
}

void	adding_graphics(t_all *all)
{
	int	row;
	int	col;

	row = 0;
	all->score = 0;
	all->to_score = 0;
	while (row < all->row)
	{
		col = 0;
		while (all->map[row][col])
		{
			if (all->map[row][col] == '1')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->wall, col * HEIGHT, row * WIDTH);
			}
			if (all->map[row][col] == 'C')
			{
				count_score(all, row, col);
			}
			if (all->map[row][col] == 'E')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->exit, col * HEIGHT, row * WIDTH);
				all->lexit++;
			}
			if (all->map[row][col] == 'P')
			{
				spawn_player(all, row, col);
			}
			if (all->map[row][col] == '0')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->floor, col * HEIGHT, row * WIDTH);
			}
			col++;
		}
		row++;
	}
}
