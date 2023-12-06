/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:18:32 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/06 06:40:05 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	map_cols(char *str)
{
	int	cols;

	cols = 0;
	while (str[cols] != '\0')
		cols++;
	if (str[cols - 1] == '\n')
		cols--;
	return (cols);
}

static int	new_line(t_layout *map, char *str)
{
	char	**temp;
	int		i;

	if (!str)
		return (0);
	i = 0;
	map->row++;
	temp = (char **)malloc(sizeof(char *) * (map->row + 1));
	temp[map->row] = NULL;
	while (i < map->row - 1)
	{
		temp[i] = map->maps[i];
		i++;
	}
	temp[i] = str;
	if (map->maps)
		free(map->maps);
	map->maps = temp;
	return (1);
}

int	read_map(t_layout *map, char **arr)
{
	char	*readmap;

	map->fd = open(*arr, O_RDONLY);
	if (map->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(map->fd);
		if (!new_line(map, readmap))
			break ;
	}
	close (map->fd);
	map->col = map_cols(map->maps[0]);
	return (1);
}
