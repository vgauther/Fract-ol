/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:01:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/10 16:37:00 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	error_in_argv(void)
{
	ft_putstr("\nThe name of the fractal is not good.\n\n"); 
	ft_putstr("LIST OF VALIDS NAMES: \n");
	ft_putstr("- 'julia'\n- 'mandelbrot'\n");
	exit(0);
}

void	usage(void)
{
	ft_putstr("Usage : ./fractol <fractal name>\n");
	exit(0);
}
