/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/30 11:35:27 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

	/*all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * 64, all.row * 64, "Red Carrot Redemption");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);*/



void	init_game()
{
	int			i;
	int			j;
	t_all		all;

	all.can_finish = 0;
	ft_memset(&all, 0, sizeof(t_all));
	read_map(&all, all.path[all.current_level]);
	//check_map_errors(&all);
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * HEIGHT, all.row * WIDTH, "Red Carrot Redemptiom");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	mlx_loop(all.mlx_ptr);
}
