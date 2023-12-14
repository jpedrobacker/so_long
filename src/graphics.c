/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:42:25 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/14 14:12:13 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	graphics_env(t_all *all)
{
	int	i;
	int	j;

	all->floor = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/floor.xpm", &i, &j);
	all->wall = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/cactus.xpm", &i, &j);
	//all->exit = mlx_xpm_file_to_image(all->mlx_ptr, "", &i, &j);
	//all->coin = mlx_xpm_file_to_image(all->mlx_ptr, "", &i, &j);
	all->player = mlx_xpm_file_to_image(all->mlx_ptr, "../sprites/outlaw.xpm", &i, &j);
}

static void	count_score(t_all *all, int row, int col)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->coin, col *64, row *64);
	all->score++;
}

static void	spawn_player(t_all *all, int row, int col)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->player, col * 64, row *64);
	all->pos_x = col;
	all->pos_y = row;
}

void	adding_graphics(t_all *all)
{
	int	row;
	int	col;

	row = 0;
	all->score = 0;
	while (row < all->row)
	{
		col = 0;
		while (all->map[row][col])
		{
			if (all->map[row][col] == '1')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->wall, col * 64, row * 64);
			}
			/*if (all->map[row][col] == 'C')
			{
				count_score(all, score, row, col);
			}*/
			if (all->map[row][col] == 'P')
			{
				spawn_player(all, row, col);
			}
			if (all->map[row][col] == '0')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->floor, col * 64, row * 64);
			}
			col++;
		}
		row++;
	}
}
