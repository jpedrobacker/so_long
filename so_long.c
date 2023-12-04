/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:38:37 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/01 22:30:21 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	f(int keysym, t_mlx_data *data)
{
	printf("Pressed the key %s", keysym);
	sleep(1);
	return (1);
}

int	change_color(t_mlx_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, data->color, "Olá a todos");
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data ->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}

int main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "my window");
	data.color = 0xFF0000;

	mlx_key_hook(data.win_ptr, f, &data);
	mlx_key_hook(data.mlx_ptr, change_color, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
