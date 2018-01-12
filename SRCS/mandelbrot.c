/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:19 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/12 13:24:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"
#include "math.h"

void	mandelbrot(t_mlx_data win1)
{
	int res;
	int x;
	int y;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	int i;
	float x1;
	float x2;
	float y1;
	float y2;
	float tmp;
	float x_image;
	float y_image;
	float zoom;

	zoom = 100;
	x = 0;
	y = 0;
	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	res = 100;
	x_image = (x2 - x1) * zoom;
	y_image = (y2 - y1) * zoom;
	while(x <= x_image)
	{
		while(y <= y_image)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			i = 0;
			z_r = 0;
			z_i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < res)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if(i == res)
				mlx_pixel_put(win1.mlx, win1.win, x, y, 0);
			else
				mlx_pixel_put(win1.mlx, win1.win, x, y, i*255/res);
			y++;
		}
		y = 0;
		x++;
	}
}
