/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:35:45 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/30 11:34:59 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	start(int key, t_all *all)
{
	if (key == 65293)
	{
		mlx_destroy_display(all->mlx_ptr);
		init_game();
	}
	if (key == 65307)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		free(all->mlx_ptr);
	}
	printf("%d key \n", key);
	return (1);
}

int main()
{
	t_all	all;
	int		i;
	int		j;
	char	*path[4];

	path[0] = "../tests/map1.ber";
	path[1] = "../tests/map2.ber";
	path[2] = "../tests/map3.ber";
	path[3] = NULL;
	all.current_level = 0;
	all.path = path;
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, 854, 480, "Red Carrot Redemption");
	all.menu = mlx_xpm_file_to_image(all.mlx_ptr, "../sprites/RCR_menu.xpm", &i, &j);
	mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.menu, 0, 0);
	mlx_key_hook(all.win_ptr, start, &all);
	mlx_loop(all.mlx_ptr);
}
