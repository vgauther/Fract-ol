#include "./minilibx_macos/mlx.h"

void *carre(void *win, void *mlx);

int main(int argc, const char *argv[])
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	int x;
	x = 50;
	win = mlx_new_window(mlx, 1000,1000, "yo");
	mlx_pixel_put(mlx, win, x +1, x+10, 0xff0000);
	mlx_pixel_put(mlx, win, x+2, x+10, 0xff0000);
	mlx_pixel_put(mlx, win, x+3, x+10, 0xff0000);
	mlx_pixel_put(mlx, win, x+4, x+10, 0xff0000);
	mlx_pixel_put(mlx, win, x+5, x+10, 0xff0000);
	carre(win, mlx);
	mlx_loop(mlx);
	return 0;
}


void	*carre(void *win, void *mlx)
{
	int x;
	int y;

	x = 50;
	y = 50;
	while(y != 150)
	{
		x = 50;
		while(x != 150)
		{
			mlx_pixel_put(mlx, win, x+1, y+1, 0xff0000);
			x++;
		}
		y++;
	}
	return(win);
}
