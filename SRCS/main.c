/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/16 15:00:50 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		keyhook(int keycode, void *param)
{
	t_mlx_data		*win1;
	t_param			*p;
	t_mandelbrot	*v;
	int				tmp;

	p = (t_param *)param;
	//printf("%d\n", keycode);
	win1 = &p->win1;
	v = &p->v;
	tmp = v->token;
	if(keycode == 53)
		exit(0);
	if(keycode == 124 && v->token < 3)
		v->token++;
	else if (keycode == 123 && v->token > 0)
		v->token--;
	if (tmp != v->token)
		tmp = 42;
	if (keycode == 27)
	{
		v->res += 1;
		tmp = 21;
	}
	else if (keycode == 24)
	{
		v->res -= 1;
		tmp = 21;
	}
	if (keycode == 2)
	{
		v->fs.x1 -= 0.1;
		v->fs.x2 -= 0.1;
		tmp = 21;
	}
	if (keycode == 0)
	{
		v->fs.x1 += 0.1;
		v->fs.x2 += 0.1;
		tmp = 21;
	}
	if(keycode == 13)
	{
		v->fs.y1 += 0.1;
		v->fs.y2 += 0.1;
		tmp = 21;
	}
	if(keycode == 1)
	{
		v->fs.y1 -= 0.1;
		v->fs.y2 -= 0.1;
		tmp = 21;
	}
	if (v->token == 2 && (tmp == 21 || tmp == 42))
	{
		if(tmp == 42)
			*v = init_var(*win1);
		mlx_clear_window(win1->mlx, win1->win);
		mandelbrot(*win1, *v);
	}
	if (v->token == 1 && (tmp == 21 || tmp == 42))
	{
		mlx_clear_window(win1->mlx, win1->win);
		if(tmp == 42)
			*v = init_var_julia(*win1);
		julia(*win1, *v);
	}
	return(0);
}

int		mouse_hook(int keycode,int x, int y, void *param)
{
	t_mlx_data *win1;
	t_mandelbrot *v;
	t_param *p;

	p = (t_param *)param;
	win1 = &p->win1;
	v = &p->v;
	x = 0;
	y = 0;
	mlx_clear_window(win1->mlx, win1->win);
	if(keycode == 5)
		v->zoom += 30;
	else if(keycode == 4)
		v->zoom -= 30;
	if (v->token == 2)
		mandelbrot(*win1, *v);
	else if (v->token == 1)
		julia(*win1, *v);
	return (0);
}

int		what_is_the_fract(char *str, t_mlx_data win1, t_mandelbrot *v)
{
	if (ft_strcmp("julia", str) == 0)
	{
		*v = init_var_julia(win1);
		julia(win1, *v);
		return(1);
	}
	else if (ft_strcmp("mandelbrot", str) == 0)
	{
		mandelbrot(win1, *v);
		return(2);
	}
	return(0);
}

int main(int argc, char **argv)
{
	t_mlx_data	win1;
	t_mandelbrot v;
	t_param		param;

	if (argc != 2)
		usage();
	error_in_argv(argv[1]);
	win1.size.len_win = 810;
	win1.size.hei_win = 660;
	win1.mlx = mlx_init();
	win1.win = mlx_new_window(win1.mlx, win1.size.len_win, win1.size.hei_win, "FRACTOL");
	v = init_var(win1);
	if(what_is_the_fract(argv[1], win1, &v) == 0)
		return 0;
	param.win1 = win1;
	param.v = v;
	mlx_hook(win1.win,2 ,0 ,keyhook , &param);
	mlx_mouse_hook(win1.win, mouse_hook, &param);
	mlx_loop(win1.mlx);
	return (0);
}
