/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:47:49 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/11 13:35:16 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_elems(t_all *all)
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

void	count_elems(t_all *all, char **temp_map)
{
	int	row;
	int	col;

	row = 0;
	all->to_score = 0;
	while (row < all->row)
	{
		col = 0;
		while (temp_map[row][col])
		{
			if (temp_map[row][col] == 'C')
				all->to_score++;
			if (temp_map[row][col] == 'E')
				all->lexit++;
			if (temp_map[row][col] == 'P')
			{
				all->lplayer++;
				all->pos_x = col;
				all->pos_y = row;
			}
			col++;
		}
		row++;
	}
}
