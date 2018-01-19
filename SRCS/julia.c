/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:16:05 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/19 18:45:27 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"

t_fract			init_var_julia(t_mlx_data win1)
{
	t_fract v;

	v.color = 255;
	v.token = 1;
	v.fs.x1 = -1.5;
	v.fs.y1 = -1.20;
	v.zoom = 275;
	v.res = 150;
	v.c_r = 0.285;
	v.c_i = 0.01;
	v.pause = 1;
	if (win1.win)
		return (v);
	return (v);
}

static void		zero_var(t_fract *v, t_pixel pixel)
{
	v->i = 0;
	v->z_r = pixel.x / v->zoom + v->fs.x1;
	v->z_i = pixel.y / v->zoom + v->fs.y1;
}

void			end_fract(t_mlx_data win1, t_fract v)
{
	mlx_put_image_to_window(win1.mlx, win1.win, v.img.img, 0, 0);
	mlx_destroy_image(win1.mlx, v.img.img);
}

void			julia(t_mlx_data win1, t_fract v)
{
	t_pixel pixel;

	start_fract(&v, win1, &pixel);
	while (pixel.x < win1.size.len_win)
	{
		pixel.y = -1;
		while (++pixel.y < win1.size.hei_win)
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
