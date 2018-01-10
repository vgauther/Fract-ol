/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:50:46 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 17:48:16 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*y;

	i = 0;
	y = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (&y[i]);
		i++;
	}
	if (s[i] == c)
		return (&y[i]);
	return (NULL);
}
