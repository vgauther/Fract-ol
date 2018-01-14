/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:39 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/14 13:13:00 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

typedef struct	s_size_win
{
	int		len_win;
	int		hei_win;
}				t_size_win;

typedef struct	s_mlx_data
{
	void		*mlx;
	void		*win;
	t_size_win	size;
}				t_mlx_data;

typedef struct	s_pixel
{
	int x;
	int y;
	int color;
}				t_pixel;

typedef struct	s_img
{
	void *img;
	char *img_str;
	int		bits;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_fratcol_size
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	x_image;
	float	y_image;
}				t_fractol_size;

typedef struct	s_mandelbrot
{
	float zoom;
	float tmp;
	int i;
	int res;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	t_img img;
	t_fractol_size fs;
}				t_mandelbrot;

void			usage(void);
void			mandelbrot(t_mlx_data win1);
void			julia();
void			error_in_argv(void);
void			put_pixel_image(t_pixel pixel, t_mlx_data win1, char *str, int color);

#endif
