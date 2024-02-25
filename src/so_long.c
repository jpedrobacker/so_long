/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2024/02/25 18:13:34 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_elems(t_all *all)
{
	int	x;

	x = 0;
	if (all->lplayer != 1)
	{
		ft_printf("No players\n");
		x++;
	}
	if (all->lexit != 1)
	{
		ft_printf("No exit found\n");
		x++;
	}
	if (all->to_score < 1)
	{
		ft_printf("No collectibles found\n");
		x++;
	}
	if (x > 0)
		to_free(all);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_all	all;
	if (argc != 2)
		return (0);
	all.can_finish = 0;
	ft_memset(&all, 0, sizeof(t_all));
	read_map(&all, argv[1]);
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * HEIGHT, \
	all.row * WIDTH, "Red Carrot Redemptiom");
	graphics_env(&all);
	adding_graphics(&all);
	check_map_errors(&all);
	check_elems(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	mlx_hook(all.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(all.mlx_ptr);
}
