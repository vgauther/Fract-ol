/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:14:48 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:01 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tab;

	if (!(tab = (void *)malloc(size)))
		return (0);
	else
	{
		ft_bzero(tab, size);
	}
	return (tab);
}
