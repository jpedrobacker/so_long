/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:53:22 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/18 13:54:02 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	to_free(t_all *all)
{
	to_free_game(all, 1);
	exit(0);
}

int	to_free_incomplete(t_all *all)
{
	to_free_game_map(all);
	exit(0);
}
