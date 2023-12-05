/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:15 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/04 19:16:09 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void	*spawn_player(void *ptr)
{
	void	*img;
	int		img_w;
	int		img_h;
	char	*path = "../sprites/player.xpm";

	img = mlx_xpm_file_to_image(ptr, path, &img_w, &img_h);
	return (img);
}
