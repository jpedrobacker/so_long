/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:18:32 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/07 18:45:55 by jbergfel         ###   ########.fr       */
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

static int	new_line(t_layout *layout, char *str)
{
	char	**temp;
	int		i;

	if (!str)
		return (0);
	i = 0;
	layout->row++;
	temp = (char **)malloc(sizeof(char *) * (layout->row + 1));
	temp[layout->row] = NULL;
	while (i < layout->row - 1)
	{
		temp[i] = layout->map[i];
		i++;
	}
	temp[i] = str;
	if (layout->map)
		free(layout->map);
	layout->map = temp;
	return (1);
}

int	read_map(t_layout *layout, char **arr)
{
	char	*readmap;

	layout->fd = open(*arr, O_RDONLY);
	if (layout->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(layout->fd);
		if (!new_line(layout, readmap))
			break ;
	}
	close (layout->fd);
	layout->col = map_cols(layout->map[0]);
	return (1);
}
