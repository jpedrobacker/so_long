/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:27:58 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/25 17:12:34 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_imgs(t_all *all)
{
	mlx_destroy_image(all->mlx_ptr, all->player);
	mlx_destroy_image(all->mlx_ptr, all->floor);
	mlx_destroy_image(all->mlx_ptr, all->wall);
	mlx_destroy_image(all->mlx_ptr, all->exit);
	mlx_destroy_image(all->mlx_ptr, all->coin);
}

static void	free_lib(t_all *all)
{
	free_imgs(all);
	mlx_destroy_window(all->mlx_ptr, all->win_ptr);
	mlx_destroy_display(all->mlx_ptr);
	free(all->mlx_ptr);
}

void	to_free_game_map(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->row)
		free(all->map[i++]);
	free(all->map);
}

void	to_free_game(t_all *all)
{
	to_free_game_map(all);
	free_lib(all);
}
