/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:42:25 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/11 12:28:24 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	graphics_env(t_all *all)
{
	int	row;
	int	col;

	all->floor = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/floor.xpm", &row, &col);
	all->wall = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/cactus.xpm", &row, &col);
	all->exit = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/horse.xpm", &row, &col);
	all->coin = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/carrot.xpm", &row, &col);
	all->player = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/outlaw_foward.xpm", &row, &col);
}

static void	score_exit(t_all *all, int row, int col)
{
	if (all->map[row][col] == 'C')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->coin, \
		col * HEIGHT, row * WIDTH);
	else if (all->map[row][col] == 'E')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->exit, \
		col * HEIGHT, row * WIDTH);
}

static void	spawn_player(t_all *all, int row, int col)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->player, \
	col * HEIGHT, row * WIDTH);
	all->pos_x = col;
	all->pos_y = row;
}

static void	floor_wall(t_all *all, int row, int col)
{
	if (all->map[row][col] == '0')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->floor, \
		col * HEIGHT, row * WIDTH);
	else if (all->map[row][col] == '1')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->wall, \
		col * HEIGHT, row * WIDTH);
}

void	adding_graphics(t_all *all)
{
	int	row;
	int	col;

	row = 0;
	while (row < all->row)
	{
		col = 0;
		while (all->map[row][col])
		{
			if (all->map[row][col] == '1' || all->map[row][col] == '0')
				floor_wall(all, row, col);
			if (all->map[row][col] == 'C' || all->map[row][col] == 'E')
				score_exit(all, row, col);
			if (all->map[row][col] == 'P')
				spawn_player(all, row, col);
			col++;
		}
		row++;
	}
}
