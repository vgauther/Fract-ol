/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:19 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/10 17:47:05 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"
#include "math.h"

void	mandelbrot(t_mlx_data win1)
{
	int res;
	int x;
	int y;
	int z;
	int c;
	int i;

	x = 0;
	y = 0;
	res = 50;
	while(y != 500 && x != 500)
	{
		i = 0;
		z = 0;
		c = x + i * y;
		z = z * z + c;
	i++;
		printf("%s\n", "test");
		while ((sqrt(pow(z,2) + pow(c,2)))< 2 && i < res)
		{
			z = z * z + c;
			i++;
		}
		if(i == res)
			mlx_pixel_put(win1.mlx, win1.win, x, y, 0xFF0000);
		if(x == 0 && y != 0)
		{
			x = 0;
			y++;
		}
		x++;
	}
}
