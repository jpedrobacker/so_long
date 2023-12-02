/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:39:18 by jbergfel          #+#    #+#             */
/*   Updated: 2023/10/20 13:25:39 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*stri;

	stri = (char *)str;
	i = ft_strlen(stri);
	while (i >= 0)
	{
		if (stri[i] == c)
			return (stri + i);
		i--;
	}
	return (0);
}
