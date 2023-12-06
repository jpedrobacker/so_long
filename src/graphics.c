/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:42:25 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/06 12:52:55 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	graphics(t_layout *data)
{
	int	i;
	int	j;

	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/kanye.xpm", &i, &j);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/poze-do-gordo.xpm", &i, &j);
}


void	adding_graphics(t_layout *data)
{

	int	col;
	int	row;

	row = 0;
	while (row < data->row)
	{
		col = 0;
		while (data->maps[row][col])
		{
			if (data->maps[row][col] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, col * 40, row * 40);
			}
			if (data->maps[row][col] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, col * 40, row * 40);
			}
			col++;
		}
		row++;
	}
}
