/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:19 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/19 18:31:32 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"
#include "math.h"

t_fract			init_var_man(t_mlx_data win1)
{
	t_fract v;

	v.zoom = 280;
	v.fs.x1 = -2.1;
	v.fs.y1 = -1.2;
	v.res = 200;
	v.token = 2;
	v.color = 255;
	if (win1.win)
		return (v);
	return (v);
}

static void		zero_var(t_fract *v, t_pixel pixel)
{
	v->c_r = pixel.x / v->zoom + v->fs.x1;
	v->c_i = pixel.y / v->zoom + v->fs.y1;
	v->i = 0;
	v->z_r = 0;
	v->z_i = 0;
}

void			start_fract(t_fract *v, t_mlx_data win1, t_pixel *pixel)
{
	v->img.img = mlx_new_image(win1.mlx, win1.size.len_win, win1.size.hei_win);
	v->img.img_str = mlx_get_data_addr(v->img.img, &v->img.bits, \
			&v->img.size_line, &v->img.endian);
	pixel->x = 0;
}

void			mandelbrot(t_mlx_data win1, t_fract v)
{
	t_pixel pixel;

	start_fract(&v, win1, &pixel);
	while (pixel.x <= win1.size.len_win)
	{
		pixel.y = -1;
		while (++pixel.y <= win1.size.hei_win)
		{
			zero_var(&v, pixel);
			while ((v.z_r * v.z_r + v.z_i * v.z_i) < 4 && v.i < v.res)
			{
				v.tmp = v.z_r;
				v.z_r = v.z_r * v.z_r - v.z_i * v.z_i + v.c_r;
				v.z_i = 2 * v.z_i * v.tmp + v.c_i;
				v.i++;
			}
			if (v.i == v.res)
				put_pixel_image(pixel, win1, v.img.img_str, 0);
			else
				put_pixel_image(pixel, win1, v.img.img_str, \
						v.i * v.color / 255 << 10);
		}
		pixel.x++;
	}
	end_fract(win1, v);
}
