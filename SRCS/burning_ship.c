/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:11:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/18 16:46:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"
#include <math.h>
void	burning_ship(t_mlx_data mlx)
{
	float x1;
	float y1;
	float x;
	float y;
	int i;
	int res;
	float tmp;
	t_pixel pixel;
	pixel.x = 0;
	pixel.y = 0;
	res = 50;
	t_mandelbrot v;

	x = 1.2;
	y = 1.2;
	v.img.img = mlx_new_image(mlx.mlx, mlx.size.len_win, mlx.size.hei_win);
	v.img.img_str = mlx_get_data_addr(v.img.img, &v.img.bits, &v.img.size_line, &v.img.endian);
	while (pixel.x != mlx.size.len_win)
	{
		while (pixel.y != mlx.size.hei_win)
		{
			x1 = 0;
			y1 = 0;
			i = 0;
			while (x1*x1 + y1*y1 < 4 && i < res)
			{
				tmp = x1*x1 - y1*y1 + x;
				y1 = fabsf(2*x1*y1 + y);
				x1 = fabsf(tmp);
				i++;
			}
			if (i == res)
				put_pixel_image(pixel, mlx,v.img.img_str, 255);
			pixel.y++;
		}
		pixel.x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, v.img.img, 0, 0);
	mlx_destroy_image(mlx.mlx, v.img.img);
}
