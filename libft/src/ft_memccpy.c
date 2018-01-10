/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:30:08 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/12 17:49:20 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*subsrc;
	unsigned char	*subdesti;

	i = 0;
	subsrc = (unsigned char *)src;
	subdesti = (unsigned char *)dest;
	while (i < n)
	{
		subdesti[i] = subsrc[i];
		if (subsrc[i] == (unsigned char)c)
			return (++dest + i);
		i++;
	}
	return (NULL);
}
