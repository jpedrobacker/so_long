/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:52:28 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/02 11:52:19 by jbergfel         ###   ########.fr       */
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
		if (!(all->map[0][y] == '1' && all->map[all->row - 1][y] == '1'))
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
	y = all->col;
	while (x < all->row)
	{
		if (!(all->map[x][0] == '1' && all->map[x][y - 1] == '1'))
			return (0);
		x++;
	}
	return (1);
}

void	check_walls(t_all *all)
{
	int	hwall;
	int	vwall;
	int	rec;

	rec = is_ok(all);
	if (!rec)
	{
		ft_printf("Error!\nInvalid Map!\n");
		to_free_incomplete(all);
	}
	hwall = check_hwall(all);
	vwall = check_vwall(all);
	if (!hwall || !vwall)
	{
		ft_printf("Error!\nInvalid Map!\n");
		to_free_incomplete(all);
	}
}

static void	map_flood(t_all *all, char **temp_map, int x, int y)
{
	if (all->map_error)
		return ;
	if (temp_map[y][x] == '1' || temp_map[y][x] == 'E')
		return ;
	if (temp_map[y][x] == 'C')
		all->score_ok++;
	if (temp_map[y][x + 1] == 'E' || temp_map[y][x - 1] == 'E' ||
		temp_map[y + 1][x] == 'E' || temp_map[y - 1][x] == 'E')
		all->can_finish = 1;
	temp_map[y][x] = '1';
	if (temp_map[y][x + 1] != '1')
		map_flood(all, temp_map, x + 1, y);
	if (temp_map[y][x - 1] != '1')
		map_flood(all, temp_map, x - 1, y);
	if (temp_map[y + 1][x] != '1')
		map_flood(all, temp_map, x, y + 1);
	if (temp_map[y - 1][x] != '1')
		map_flood(all, temp_map, x, y - 1);
}

void	check_map_errors(t_all *all)
{
	int		x;
	int		count;
	char	**temp_map;

	check_walls(all);
	count_elems(all);
	check_elems(all);
	temp_map = (char **)malloc((all->col) * sizeof(char *));
	count = -1;
	while (++count < all->row)
		temp_map[count] = ft_strdup(all->map[count]);
	temp_map[count] = '\0';
	map_flood(all, temp_map, all->pos_x, all->pos_y);
	x = 0;
	while (temp_map[x])
	{
		free(temp_map[x]);
		x++;
	}
	free(temp_map);
	if (all->can_finish == 0 || all->score_ok < all->to_score)
	{
		ft_printf("Error!\nNo path available!\n");
		to_free_incomplete(all);
	}
}
