/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:28:26 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/14 12:46:06 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"

void	put_pixel_image(t_pixel pixel, t_mlx_data win1, char *str, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	pixel.color = color;
	r = (pixel.color >> 16) & 0xff;
	g = (pixel.color >> 8) & 0xff;
	b = pixel.color & 0xff;
	str[(pixel.x * 4) + (win1.size.len_win * 4 * pixel.y)] = b;
	str[(pixel.x * 4) + (win1.size.len_win * 4 * pixel.y) + 1] = g;
	str[(pixel.x * 4) + (win1.size.len_win * 4 * pixel.y) + 2] = r;
	str[(pixel.x * 4) + (win1.size.len_win * 4 * pixel.y) + 3] = 0;
}
