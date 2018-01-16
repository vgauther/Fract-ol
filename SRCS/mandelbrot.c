/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:19 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/16 15:03:54 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"
#include "math.h"

t_mandelbrot init_var(t_mlx_data win1)
{
	t_mandelbrot v;

	v.zoom = 280;
	v.fs.x1 = -2.1;
	v.fs.x2 = 0.6;
	v.fs.y1 = -1.2;
	v.fs.y2 = 1.2;
	v.res = 200;
	v.fs.x_image = (v.fs.x2 - v.fs.x1) * v.zoom;
	v.fs.y_image = (v.fs.y2 - v.fs.y1) * v.zoom;
	v.token = 2;
	if(win1.win)
		return (v);
	return (v);
}

void	mandelbrot(t_mlx_data win1, t_mandelbrot v)
{
	t_pixel pixel;

	v.img.img = mlx_new_image(win1.mlx, win1.size.len_win, win1.size.hei_win);
	v.img.img_str = mlx_get_data_addr(v.img.img, &v.img.bits, &v.img.size_line, &v.img.endian);
	pixel.x = 0;
	pixel.y = 0;
	while(pixel.x <= win1.size.len_win)
	{
		while(pixel.y <= win1.size.hei_win)
		{
			v.c_r = pixel.x / v.zoom + v.fs.x1;
			v.c_i = pixel.y / v.zoom + v.fs.y1;
			v.i = 0;
			v.z_r = 0;
			v.z_i = 0;
			while ((v.z_r * v.z_r + v.z_i * v.z_i) < 4 && v.i < v.res)
			{
				v.tmp = v.z_r;
				v.z_r = v.z_r * v.z_r - v.z_i * v.z_i + v.c_r;
				v.z_i = 2 * v.z_i * v.tmp + v.c_i;
				v.i++;
			}
			if(v.i == v.res)
				put_pixel_image(pixel, win1, v.img.img_str, 0);
			else
				put_pixel_image(pixel, win1, v.img.img_str, v.i * 65025 / v.res);
			pixel.y++;
		}
		pixel.y = 0;
		pixel.x++;
	}
	mlx_put_image_to_window(win1.mlx, win1.win, v.img.img, 0, 0);
	mlx_destroy_image(win1.mlx, v.img.img);
}
