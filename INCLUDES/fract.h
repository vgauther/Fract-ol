/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:28:39 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/11 22:32:46 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

typedef struct	s_mlx_data
{
	void	*mlx;
	void	*win;
}				t_mlx_data;

void			usage(void);
void			mandelbrot(t_mlx_data win1);
void			julia();
void	error_in_argv(void);

#endif
