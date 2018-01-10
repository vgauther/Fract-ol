/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:20:07 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 18:02:02 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const char		*s;

	d = (unsigned char *)dest;
	s = (const char *)src;
	while (0 < n--)
		d[n] = s[n];
	return (d);
}
