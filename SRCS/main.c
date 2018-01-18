/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/18 16:34:01 by vgauther         ###   ########.fr       */
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
	printf("%d\n", keycode);
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
	if(keycode == 45)
	{
		v->c_i += 0.001;
		tmp = 21;
	}
	if(keycode == 11)
	{
		tmp = 21;
		v->c_r += 0.001;
	}
	if (keycode == 8)
	{
		if (v->color == 100000000 && tmp != 21)
		{
			v->color = 255;
			tmp = 21;
		}
		if (v->color == 255 && tmp != 21)
		{
			v->color = 65025;
			tmp = 21;
		}
		if (v->color == 65025 && tmp != 21)
		{
			v->color = 100000000;
		}
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
	else if (ft_strcmp("burning_ship", str) == 0)
	{
		burning_ship(win1);
		return(3);
	}
	return(0);
}

int	hook(int x, int y, void *param)
{
	t_param *p;
	t_mlx_data *mlx;
	t_mandelbrot *v;
	//printf("x: %d\n", x);
	//printf("y: %d\n", y);
	p = (t_param *)param;
	mlx = &p->win1;
	v = &p->v;
	v->token = 0;
	if (v->token == 1)
	{
		//v->c_r = ((mlx->size.len_win/ (2 - x)) / mlx->size.len_win) * 2;
		//	if((v->c_r = 0.285 - (0.0001*(mlx->size.len_win - x))) >= 0.24)
				v->c_r = 0.285 + (0.0001*(mlx->size.hei_win - x -100));
				v->c_i = 0.001 + (0.0001*(mlx->size.hei_win - y -100));

		printf("%.2f\n", v->c_r);
		mlx_clear_window(mlx->mlx, mlx->win);
		julia(*mlx, *v);
	}
	x = 0;
	y = 0;
	//mlx_pixel_put(mlx->mlx, mlx->win, x, y, 255);
	return 0;
}

int main(int argc, char **argv)
{
	t_mlx_data	win1;
	t_mandelbrot v;
	t_param		param;

	if (argc != 2)
		usage();
	error_in_argv(argv[1]);
	win1.size.len_win = 800;
	win1.size.hei_win = 660;
	win1.mlx = mlx_init();
	win1.win = mlx_new_window(win1.mlx, win1.size.len_win, win1.size.hei_win, "FRACTOL");
	v = init_var(win1);
	v.color = 255;
	if(what_is_the_fract(argv[1], win1, &v) == 0)
		return 0;
	param.win1 = win1;
	param.v = v;
	mlx_hook(win1.win,2 ,0 ,keyhook , &param);
	mlx_mouse_hook(win1.win, mouse_hook, &param);
	mlx_hook(win1.win, 6, 0, hook, &param);
	mlx_loop(win1.mlx);
	return (0);
}
