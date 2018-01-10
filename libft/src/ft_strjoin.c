/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:52:44 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 17:45:38 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		x;

	if (s1 && s2)
	{
		x = -1;
		i = (ft_strlen(s1) + ft_strlen(s2));
		if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = 0;
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[++x])
		{
			tab[i] = s2[x];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
