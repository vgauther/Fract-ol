/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:58:07 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 17:41:23 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t ldst;
	size_t lsrc;
	size_t ret;

	i = 0;
	j = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen((char *)src);
	if (size <= ldst)
		ret = lsrc + size;
	else
	{
		ret = lsrc + ldst;
		j = size - ldst - 1;
		while (j > 0)
		{
			dst[ldst + i] = src[i];
			i++;
			j--;
		}
		dst[ldst + i] = '\0';
	}
	return (ret);
}
