/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:14:32 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/04 16:18:13 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include <stdlib.h>

typedef struct s_layout
{
	int	row;
	int	col;
	int	exit;
	int	coin;
	int	player;
}	t_layout;

#endif
