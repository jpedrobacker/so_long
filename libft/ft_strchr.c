/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:38:50 by jbergfel          #+#    #+#             */
/*   Updated: 2023/10/20 13:24:40 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*stri;

	stri = (char *)str;
	i = 0;
	while (stri[i] != c)
	{
		if (stri[i] == '\0')
			return (0);
		i++;
	}
	return (stri + i);
}
