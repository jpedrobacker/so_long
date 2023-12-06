/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:20:49 by jbergfel          #+#    #+#             */
/*   Updated: 2023/12/05 11:43:08 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checks.h"

t_layout	new_layout(void)
{
	t_layout	layout;

	layout.row = 0;
	layout.col = 0;
	layout.exit = 0;
	layout.coin = 0;
	layout.player = 0;
	return (layout);
}


