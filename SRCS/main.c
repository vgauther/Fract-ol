/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/12 21:38:34 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		keyhook(int keycode, void *param)
{
	param = NULL;
	if(keycode == 53)
	{
		exit(0);
	}
	return(0);
}

int		what_is_the_fract(char *str, t_mlx_data win1)
{
	if (ft_strcmp("julia", str) == 0)
		return(1);
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
	win1.mlx = mlx_init();
	win1.win = mlx_new_window(win1.mlx, 500, 500, "FRACTOL");
	if(what_is_the_fract(argv[1], win1) == 0)
	  error_in_argv();
	mlx_hook(win1.win,2,0,keyhook, NULL);
	mlx_loop(win1.mlx);
	return 0;
}
