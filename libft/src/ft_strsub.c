/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:43:23 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/10 17:41:12 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** fonction qui renvoie une une string a partir de s en fonction
** de start et de len
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i != len)
		{
			tab[i] = s[start];
			start++;
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
