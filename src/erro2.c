/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:47:49 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/12 15:32:16 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_elems(t_all *all)
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
		to_free_incomplete(all);
}

void	check_digits(t_all *all, char d)
{
	if (d == '1' || d == '0' || d == 'P' \
	|| d == 'C' || d == 'E' || d == '\n' || d == '\0')
		return ;
	else
		to_free_incomplete(all);
}

void	count_elems(t_all *all)
{
	int	row;
	int	col;

	row = 0;
	all->to_score = 0;
	while (row < all->row)
	{
		col = 0;
		while (all->map[row][col])
		{
			check_digits(all, all->map[row][col]);
			if (all->map[row][col] == 'C')
				all->to_score++;
			if (all->map[row][col] == 'E')
				all->lexit++;
			if (all->map[row][col] == 'P')
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
