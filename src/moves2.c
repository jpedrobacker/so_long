/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:57:22 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/18 14:19:02 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	w_key(t_all *all, int col, int row)
{
	int	k;

	row--;
	if (all->map[row][col] == '1')
		return (0);
	k = update_move(all, row, col);
	if (!k)
		return (0);
	all->map[row + 1][col] = '0';
	return (1);
}

int	s_key(t_all *all, int col, int row)
{
	int	k;

	row++;
	if (all->map[row][col] == '1')
		return (0);
	k = update_move(all, row, col);
	if (!k)
		return (0);
	all->map[row - 1][col] = '0';
	return (1);
}

int	a_key(t_all *all, int col, int row)
{
	int	i;
	int	j;
	int	k;

	all->player = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/outlaw_backwards.xpm", &i, &j);
	col--;
	if (all->map[row][col] == '1')
		return (0);
	k = update_move(all, row, col);
	if (!k)
		return (0);
	all->map[row][col + 1] = '0';
	return (1);
}

int	d_key(t_all *all, int col, int row)
{
	int	i;
	int	j;
	int	k;

	all->player = mlx_xpm_file_to_image(all->mlx_ptr, \
	"../sprites/outlaw_foward.xpm", &i, &j);
	col++;
	if (all->map[row][col] == '1')
		return (0);
	k = update_move(all, row, col);
	if (!k)
		return (0);
	all->map[row][col - 1] = '0';
	return (1);
}
