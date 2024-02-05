/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:52:28 by jbergfel          #+#    #+#             */
/*   Updated: 2024/01/31 11:46:05 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_hwall(t_all *all)
{
	int	x;
	int	y;

	x = all->col;
	y = 0;
	while (y < x)
	{
		if (all->map[0][x] == '1' && all->map[all->col - 1][y] == '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_vwall(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = all->row;

	while (x < y)
	{
		if (all->map[x][0] == '1' && all->map[x][y - 1] == '1')
			return (0);
		x++;
	}
	return (1);
}

static void	check_walls(t_all *all)
{
	int	hwall;
	int vwall;

	hwall = check_hwall(all);
	vwall = check_vwall(all);

	if (!hwall || !vwall)
	{
		printf("Map error");
		//to_free(all);
	}
}

int	check_elems(t_all *all)
{
	if (all->lplayer != 1)
	{
		//to_free(all);
		printf("Not enough players\n");
	}
	if (all->lexit != 1)
	{
		//to_free(all);
		printf("No exit found\n");
	}
	if (all->to_score < 1)
	{
		//to_free(all);
		printf("No collectibles found\n");
	}
	return (1);
}

static void	map_flood(t_all *all, char **map, int x, int y)
{
	if (all->map_error)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		all->score_ok++;
	if (map[y][x + 1] == 'E' || map[y][x - 1] == 'E' ||
		map[y + 1][x] == 'E' || map[y - 1][x] == 'E')
		all->can_finish = 1;
	map[y][x] = '1';
	if (map[y][x + 1] != '1')
		map_flood(all, map, x, y);
	if (map[y][x - 1] != '1')
		map_flood(all, map, x, y);
	if (map[y + 1][x] != '1')
		map_flood(all, map, x, y);
	if (map[y - 1][x] != '1')
		map_flood(all, map, x, y);
}

void	check_map_errors(t_all *all)
{
	char	**temp_map;

	temp_map = all->map;
	//check_walls(all);
	check_elems(all);
	//map_flood(all, temp_map, all->pos_x, all->pos_y);
}
