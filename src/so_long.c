/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/22 15:29:51 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

	/*all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * 64, all.row * 64, "Red Carrot Redemption");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);*/
int	start(int key, t_all *all)
{
	if (key == XK_j)
		all->start = 1;
	return (1);
}

void	init_game(int a)
{
	t_all		all;
	int			i;
	int			j;
	char		*path[] = {"../tests/map1.ber", "../tests/map2.ber"};

	ft_memset(&all, 0, sizeof(t_all));
	read_map(&all, path[a]);
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, 854, 480, "Red Carrot Redemption");
	all.menu = mlx_xpm_file_to_image(all.mlx_ptr, "../sprites/RCR_menu.xpm", &i, &j);
	mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.menu, 0, 0);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	if (all.start == 1)
	{
		mlx_destroy_window(all.mlx_ptr, all.win_ptr);
		all.win_ptr = mlx_new_window(all.mlx_ptr, all.col * 64, all.row *64, "Red Carrot Redemptiom");
		graphics_env(&all);
		adding_graphics(&all);
	}
	mlx_loop(all.mlx_ptr);
}
