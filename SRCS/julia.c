/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:05 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/15 15:19:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"

void	julia(t_mlx_data win1)
{
	t_pixel pixel;
	t_mandelbrot v;

	v.fs.x1 = -1;
	v.fs.x2 = 1;
	v.fs.y1 = -1.2;
	v.fs.y2 = 1.2;
	v.zoom = 200;
	v.res = 150;
	pixel.x = 0;
	pixel.y = 0;
	v.fs.x_image = (v.fs.x2 - v.fs.x1) * v.zoom;
	v.fs.y_image = (v.fs.y2 - v.fs.y1) * v.zoom;
	v.img.img = mlx_new_image(win1.mlx, win1.size.len_win, win1.size.hei_win);
	v.img.img_str = mlx_get_data_addr(v.img.img, &v.img.bits, &v.img.size_line, &v.img.endian);
	while (pixel.x < win1.size.len_win)
	{
		while (pixel.y < win1.size.hei_win)
		{
			v.i = 0;
			v.c_r = 0.285;
			v.c_i = 0.01;
			v.z_r = pixel.x / v.zoom + v.fs.x1;
			v.z_i = pixel.y / v.zoom + v.fs.y1;
			while((v.z_r * v.z_r + v.z_i * v.z_i) < 4 && v.i < v.res)
			{
				v.tmp = v.z_r;
				v.z_r = v.z_r * v.z_r - v.z_i * v.z_i + v.c_r;
				v.z_i = 2 * v.z_i * v.tmp + v.c_i;
				v.i++;
			}
			if(v.i == v.res)
				put_pixel_image(pixel, win1, v.img.img_str, 0);
			else
				put_pixel_image(pixel, win1, v.img.img_str, v.i*65025/v.res);
			pixel.y++;
		}
		pixel.y = 0;
		pixel.x++;
	}
	mlx_put_image_to_window(win1.mlx, win1.win, v.img.img, 0, 0);
	mlx_destroy_image(win1.mlx, v.img.img);
}
