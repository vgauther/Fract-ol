/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/14 21:51:58 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		keyhook(int keycode, void *param)
{
	t_mlx_data *win1;
	int i;

	i = 0;
	win1 = (t_mlx_data *)param;
	mlx_clear_window(win1->mlx, win1->win);
	if(keycode == 124 && i != 1)
		i++;
	else if (keycode == 123 && i != 0)
		i--;
		printf("%d\n", keycode);
	if (i == 1)
		what_is_the_fract("mandelbrot", *win1);
	if (i == 0)
		what_is_the_fract("julia", *win1);
	if(keycode == 53)
		exit(0);
	return(0);
}

int		mouse_hook(int keycode,int x, int y, void *param)
{
	t_mlx_data *win1;

	win1 = (t_mlx_data *)param;
	x = 0;
	y = 0;
	mlx_clear_window(win1->mlx, win1->win);
	/*if(keycode == 5)
		printf("5");
	else if(keycode == 4)
		printf("4");
	printf("tttt\n");*/
	keycode = 0;
	//mlx_clear_window(win1->mlx, win1->win);
	what_is_the_fract("julia", *win1);
	return (0);
}

int		what_is_the_fract(char *str, t_mlx_data win1)
{
	if (ft_strcmp("julia", str) == 0)
	{
		julia(win1);
		return(1);
	}
	else if (ft_strcmp("mandelbrot", str) == 0)
	{
		mandelbrot(win1);
		return(2);
	}
	return(0);
}

int main(int argc, char **argv)
{
	t_mlx_data	win1;

	if (argc != 2)
		usage();
	win1.size.len_win = 540;
	win1.size.hei_win = 480;
	win1.mlx = mlx_init();
	win1.win = mlx_new_window(win1.mlx, 540, 480, "FRACTOL");
	if(what_is_the_fract(argv[1], win1) == 0)
		error_in_argv();
	mlx_hook(win1.win,2 ,0 ,keyhook , &win1);
	
	//mlx_mouse_hook(win1.win,mouse_hook, &win1);

	mlx_loop(win1.mlx);
	return 0;
}
