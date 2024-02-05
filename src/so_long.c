/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/31 11:43:43 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	t_all	all;

	all.can_finish = 0;
	ft_memset(&all, 0, sizeof(t_all));
	read_map(&all, argv[1]);
	check_map_errors(&all);
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * HEIGHT, all.row * WIDTH, "Red Carrot Redemptiom");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	mlx_hook(all.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(all.mlx_ptr);
}
