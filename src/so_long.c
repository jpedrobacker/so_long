/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/13 22:11:40 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*int	exit_point(t_data *data, t_layout *layout)
{
	int	line;

	line = 0;
	if (data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->mlx_ptr);
	free(data->mlx_ptr);
	while (line < layout->row - 1)
		free(layout->map[line++]);
	free(layout->map);
	exit(0);
}*/

int porra(int key, t_data *data)
{
	printf("%d key\n", key);
	return (1);
}

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
	all.win_ptr = mlx_new_window(all.mlx_ptr, WIDTH, HEIGHT, "my window");
	graphics_env(&all);
	adding_graphics(&all);
	mlx_key_hook(all.win_ptr, compute_move, &all);
	mlx_loop(all.mlx_ptr);
}
