/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:51:50 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/12 17:20:32 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isnegativ(int i)
{
	if (i < 0)
		return (1);
	return (0);
}

static int		ft_intlen(int n)
{
	int i;

	i = (ft_isnegativ(n)) ? 2 : 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		cpy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cpy = n;
	len = ft_intlen(n);
	if (ft_isnegativ(n))
		cpy = -n;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	len--;
	while (len >= 0)
	{
		ret[len--] = '0' + cpy % 10;
		cpy = cpy / 10;
	}
	if (ft_isnegativ(n))
		ret[0] = '-';
	return (ret);
}
