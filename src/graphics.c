/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:42:25 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/07 16:45:25 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	graphics_env(t_data *data, t_graphics *graphics)
{
	int	i;
	int	j;

	graphics->floor = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/kanye.xpm", &i, &j);
	graphics->wall = mlx_xpm_file_to_image(data->mlx_ptr, "../sprites/poze-do-gordo.xpm", &i, &j);
}

void	adding_graphics(t_data *data ,t_layout *layout, t_graphics *img)
{
	int	col;
	int	row;

	row = 0;
	while (row < layout->row)
	{
		col = 0;
		while (layout->maps[row][col])
		{
			if (layout->maps[row][col] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->wall, col * 45, row * 45);
			}
			if (layout->maps[row][col] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->floor, col * 45, row * 45);
			}
			col++;
		}
		row++;
	}
}
