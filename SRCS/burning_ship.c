/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:11:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/19 18:46:09 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"
#include <math.h>

t_fract			init_var_ship(t_mlx_data win1)
{
	t_fract v;

	v.zoom = 200;
	v.fs.x1 = -2.3;
	v.fs.y1 = -1.9;
	v.res = 100;
	v.token = 3;
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

void			burning_ship(t_mlx_data win1, t_fract v)
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
				v.z_r = fabsf(v.z_r * v.z_r - v.z_i * v.z_i + v.c_r);
				v.z_i = fabsf(2 * v.z_i * v.tmp + v.c_i);
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
