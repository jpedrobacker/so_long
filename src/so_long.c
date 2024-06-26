/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/02 10:28:16 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 2)
		return (0);
	all.finish = 0;
	all.score = 0;
	all.moves = 1;
	ft_memset(&all, 0, sizeof(t_all));
	read_map(&all, argv[1]);
	check_map_errors(&all);
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * HEIGHT, \
	all.row * WIDTH, "so_long");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	mlx_hook(all.win_ptr, 17, 0, to_free, &all);
	mlx_loop(all.mlx_ptr);
}
