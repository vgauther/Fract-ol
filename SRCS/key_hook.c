/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:21:06 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/19 16:14:58 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fract.h"

int		valid_keycode(int keycode)
{
	if (keycode == 124 || keycode == 123 || keycode == 27 || keycode == 24)
		return (1);
	if (keycode == 2 || keycode == 0 || keycode == 1 || keycode == 13)
		return (1);
	if (keycode == 8)
		return (1);
	return (0);
}

int		color_v(int color)
{
	if (color == 100000000)
		return (255);
	if (color == 255)
		return (65025);
	if (color == 65025)
		return (100000000);
	return (255);
}

void	var(t_fract *v, int keycode)
{
	if (keycode == 24)
		v->res += 1;
	else if (keycode == 27)
		v->res -= 1;
	if (keycode == 2)
		v->fs.x1 -= 0.1;
	if (keycode == 0)
		v->fs.x1 += 0.1;
	if (keycode == 13)
		v->fs.y1 += 0.1;
	if (keycode == 1)
		v->fs.y1 -= 0.1;
	if (keycode == 8)
		v->color = color_v(v->color);
}

void	token_is_fract(t_fract *v, t_param *p, int tmp)
{
	if (v->token == 2)
	{
		if (tmp == 42)
			*v = init_var(p->win1);
		mandelbrot(p->win1, *v);
	}
	if (v->token == 1)
	{
		if (tmp == 42)
			*v = init_var_julia(p->win1);
		julia(p->win1, *v);
	}
}

int		keyhook(int keycode, void *param)
{
	t_param			*p;
	t_fract			*v;
	int				tmp;

	p = (t_param *)param;
	v = &p->v;
	tmp = v->token;
	if (keycode == 53)
		exit(0);
	if ((valid_keycode(keycode)) == 0)
		return (0);
	mlx_clear_window(p->win1.mlx, p->win1.win);
	if (keycode == 124 && v->token < 2)
		v->token++;
	else if (keycode == 123 && v->token > 1)
		v->token--;
	if (tmp != v->token)
		tmp = 42;
	var(v, keycode);
	token_is_fract(v, p, tmp);
	return (0);
}
