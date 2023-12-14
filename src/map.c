/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:18:32 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:38 by jbergfel         ###   ########.fr       */
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

static int	new_line(t_all *all, char *str)
{
	char	**temp;
	int		i;

	if (!str)
		return (0);
	i = 0;
	all->row++;
	temp = (char **)malloc(sizeof(char *) * (all->row + 1));
	temp[all->row] = NULL;
	while (i < all->row - 1)
	{
		temp[i] = all->map[i];
		i++;
	}
	temp[i] = str;
	if (all->map)
		free(all->map);
	all->map = temp;
	return (1);
}

int	read_map(t_all *all, char **arr)
{
	char	*readmap;

	all->fd = open(*arr, O_RDONLY);
	if (all->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(all->fd);
		if (!new_line(all, readmap))
			break ;
	}
	close (all->fd);
	all->col = map_cols(all->map[0]);
	return (1);
}
