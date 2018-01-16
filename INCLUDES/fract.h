/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:39 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/16 14:54:57 by vgauther         ###   ########.fr       */
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
	int token;
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

typedef struct	s_param
{
	t_mlx_data win1;
	t_mandelbrot v;
}				t_param;

void			usage(void);
void			mandelbrot(t_mlx_data win1, t_mandelbrot v);
void			error_in_argv(char *str);
void			put_pixel_image(t_pixel pixel, t_mlx_data win1, char *str, int color);
int				what_is_the_fract(char *str, t_mlx_data win1, t_mandelbrot *v);
t_mandelbrot	init_var(t_mlx_data win1);
t_mandelbrot	init_var_julia(t_mlx_data win1);
void			julia(t_mlx_data win1, t_mandelbrot v);

#endif
