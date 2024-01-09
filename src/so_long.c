/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/09 13:57:01 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(void)
{
	t_layout	layout;
	t_data		data;
	t_graphics	graphics;
	t_player	player;
	t_all		all;
	char		*path[] = {"../tests/map1.ber"};

	ft_memset(&all, 0, sizeof(t_layout));
	read_map(&all, path);
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * 64, all.row * 64, "So_long");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	mlx_loop(all.mlx_ptr);
}
