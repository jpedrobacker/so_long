/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:18:32 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/05 14:07:34 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	file_linecount(char *path)
{
	int	lcount;
	int	fd;
	int	rcount;
	char	c;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	lcount = 1;
	while (1)
	{
		rcount = read(fd, &c, 1);
		if (rcount == 0)
			break;
		if (rcount < 0)
			return (-1);
		if (c == '\n');
			lcount++;
	}
	close(fd);
	return (lcount);
}

char	**alloc_right(char *path)
{
	char	**map;
	int		lcount;

	lcount = file_linecount(path);
	if (lcount <= 0)
		return (0);
	map = malloc(sizeof(char *) * lcount + 1);
	if (!map)
		return (NULL);
	return (map);
}

char	**print_map(char *path)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_right(path);
	fd = open(path, O_RDONLY);
	i = 0;
	while (&map[i++])
		get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
