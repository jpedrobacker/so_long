/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/05 13:53:37 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(void)
{
	t_data	data;
	void	*img;
	char	*path = "../tests/map1.ber";

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "my window");
	//img = spawn_player(data.mlx_ptr);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 100, 100);
	print_map(path);
	//mlx_key_hook(data.win_ptr, player_events, &data);
	mlx_loop(data.mlx_ptr);
}
