/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:15:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/01/13 18:16:21 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_macos/mlx.h"
#include "./INCLUDES/fract.h"

typedef struct s_struc_data_point
{
	int x;
	int y;
	int color;
}				t_struc_data_point;

typedef struct s_size
{
	int size_x;
	int size_y;
}				t_size;

typedef struct s_win_info
{
	void *win;
	void *mlx;
	t_size size;
}				t_win_info;

void	put_pixel_image(t_struc_data_point point, t_win_info wininf, char *str)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

//	printf("test:%s\n", str);
	r = (point.color >> 16) & 0xff;
	g = (point.color >> 8) & 0xff;
	b = point.color & 0xff;
	str[(point.x * 4) + (wininf.size.size_x * 4 * point.y)] = b;
	str[(point.x * 4) + (wininf.size.size_x * 4 * point.y) + 1] = g;
	str[(point.x * 4) + (wininf.size.size_x * 4 * point.y) + 2] = r;
	str[(point.x * 4) + (wininf.size.size_x * 4 * point.y) + 3] = 0;
}

int main(int argc, char **argv)
{
	void *img;
	char *test;
	int bit;
	int siz;
	int end;
	t_win_info wini;
	t_struc_data_point p;
	int *x;
	int *y;
	int x1;
	int x2;

	x1 = 200;
	x2 = 200;
	x = &x1;;
	y = &x2;;
	wini.mlx = mlx_init();
	wini.size.size_x = 200;
	wini.size.size_y = 200;
	wini.win = mlx_new_window(wini.mlx, 200, 200, "test");
	img = mlx_new_image(wini.mlx, 100, 100);
	test = mlx_get_data_addr(img, &bit, &siz, &end);
	printf("%d\n", bit);
	p.y = 0;
	mlx_pixel_put(wini.mlx, wini.win, 100,100, 255);
	while(p.y != 200)
	{
		p.x = 0;
		while(p.x != 200)
		{
			p.color = 255;
			put_pixel_image(p, wini, test);
			p.x++;
		}
		p.y++;
	}
mlx_put_image_to_window(wini.mlx,wini.win, img, 0, 0);
mlx_destroy_image(wini.mlx,img);
	mlx_loop(wini.mlx);
	return 0;
}
