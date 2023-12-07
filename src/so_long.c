/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/07 16:42:26 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(void)
{
	t_layout	layout;
	t_data		data;
	t_graphics	graphics;
	char		*path[] = {"../tests/map1.ber"};

	ft_memset(&data, 0, sizeof(t_layout));
	read_map(&layout, path);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "my window");
	graphics_env(&data, &graphics);
	adding_graphics(&data, &layout, &graphics);
	//img = spawn_player(data.mlx_ptr);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 100, 100);
	//mlx_key_hook(data.win_ptr, player_events, &data);
	mlx_loop(data.mlx_ptr);
}
