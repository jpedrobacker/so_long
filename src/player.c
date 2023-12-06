/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:15 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/06 12:18:48 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*spawn_player(void *ptr)
{
	void	*img;
	int		img_w;
	int		img_h;
	char	*path = "../sprites/Kanye.xpm";

	img = mlx_xpm_file_to_image(ptr, path, &img_w, &img_h);
	return (img);
}

int	player_events(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		printf("YE out\n");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
		return (0);
	}
	if (keycode == XK_a)
	{
		printf("aaaaaaa Ye \n");
	}
	printf("YE %d\n", keycode);
	return (0);
}
