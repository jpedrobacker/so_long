/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:27:58 by jbergfel          #+#    #+#             */
/*   Updated: 2024/02/21 15:53:09 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	to_free(t_all *all)
{
	int	i;

	i = 0;
	if (all->win_ptr)
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
	free(all->mlx_ptr);
	while (i < all->row)
		free(all->map[i++]);
	free(all->map);
	exit(0);
}
