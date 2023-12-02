/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:42:03 by jbergfel          #+#    #+#             */
/*   Updated: 2023/10/19 16:42:04 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*temp;

	begin = (*(lst));
	while (begin != NULL)
	{
		temp = begin->next;
		ft_lstdelone(begin, del);
		begin = temp;
	}
	*lst = NULL;
}
