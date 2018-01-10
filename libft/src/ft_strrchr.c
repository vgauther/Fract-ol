/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:17:24 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 14:43:22 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*y;

	i = 0;
	y = (char *)s;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == c)
			return (&y[i]);
		i--;
	}
	if (s[i] == c)
		return (&y[i]);
	return (NULL);
}
