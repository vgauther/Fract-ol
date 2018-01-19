/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/19 18:45:05 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		mouse_hook(int keycode, int x, int y, void *param)
{
	t_mlx_data	*win1;
	t_fract		*v;
	t_param		*p;

	p = (t_param *)param;
	win1 = &p->win1;
	v = &p->v;
	x = 0;
	y = 0;
	mlx_clear_window(win1->mlx, win1->win);
	if (keycode == 5)
		v->zoom += 30;
	else if (keycode == 4)
		v->zoom -= 30;
	if (v->token == 2)
		mandelbrot(*win1, *v);
	else if (v->token == 1)
		julia(*win1, *v);
	else if (v->token == 3)
		burning_ship(*win1, *v);
	return (0);
}

int		what_is_the_fract(char *str, t_mlx_data win1, t_fract *v)
{
	if (ft_strcmp("julia", str) == 0)
	{
		*v = init_var_julia(win1);
		julia(win1, *v);
		return (1);
	}
	else if (ft_strcmp("mandelbrot", str) == 0)
	{
		mandelbrot(win1, *v);
		return (2);
	}
	else if (ft_strcmp("burning_ship", str) == 0)
	{
		*v = init_var_ship(win1);
		burning_ship(win1, *v);
		return (3);
	}
	return (0);
}

int		hook(int x, int y, void *param)
{
	t_param			*p;
	t_mlx_data		*mlx;
	t_fract			*v;

	p = (t_param *)param;
	mlx = &p->win1;
	v = &p->v;
	if (v->token == 1 && v->pause == 1 && x >= 0 && y >= 0 && x <= 800 \
			&& y <= 660)
	{
		v->c_r = ((mlx->size.len_win / 2 - x) / (float)mlx->size.len_win * 2);
		v->c_i = ((mlx->size.hei_win - y) / (float)mlx->size.hei_win);
		mlx_clear_window(mlx->mlx, mlx->win);
		julia(*mlx, *v);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx_data	win1;
	t_fract		v;
	t_param		param;

	if (argc != 2)
		usage();
	error_in_argv(argv[1]);
	win1.size.len_win = 800;
	win1.size.hei_win = 660;
	win1.mlx = mlx_init();
	win1.win = mlx_new_window(win1.mlx, win1.size.len_win, \
			win1.size.hei_win, "FRACTOL");
	v = init_var_man(win1);
	v.color = 255;
	what_is_the_fract(argv[1], win1, &v);
	param.win1 = win1;
	param.v = v;
	mlx_hook(win1.win, 2, 0, keyhook, &param);
	mlx_mouse_hook(win1.win, mouse_hook, &param);
	mlx_hook(win1.win, 6, 0, hook, &param);
	mlx_loop(win1.mlx);
	return (0);
}
