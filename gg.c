#include "./INCLUDES/fract.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;

}				t_window;

int        main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_window    win;
    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, 500, 500, "Fractol");
    
    float    x1 = -2.1;
    float    x2 = 0.6;
    float    y1 = -1.2;
    float    y2 = 1.2;
    float    zoom = 100;

    float    image_x = x2 - x1;
        image_x = image_x * zoom;
    float    image_y = y2 - y1;
        image_y = image_y * zoom;
        
    float    c_r;
    float    c_i;
    float    z_r;
    float    z_i;
    int    i;
    int    x;
    int    y;
    float    tmp;
    
    x = 0;
    while (x < image_x)
    {
        y = 0;    
        while (y < image_y)
        {
            c_r = x / zoom + x1;
            c_i = y / zoom + y1;
            z_r = 0;
            z_i = 0;
            i = 0;
            while (z_r * z_r + z_i * z_i < 4 && i < 50)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i++;
            }
            if (i == 50)
                mlx_pixel_put(win.mlx, win.win, x + 10, y + 10, 0xFFFFFF);
            y++;
        }
        x++;
    }
    mlx_loop(win.mlx);
    return (0);
}
