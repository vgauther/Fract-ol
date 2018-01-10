/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:27:39 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 16:54:12 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *str, const char *find)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)str;
	if (!find[i])
		return (s);
	while (s[i])
	{
		j = i;
		k = 0;
		while (s[j] == find[k])
		{
			j++;
			k++;
			if (!find[k])
				return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
