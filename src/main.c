/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/06 15:27:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/07 18:30:41 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

typedef struct  s_data {
    void    *img;
    void    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    mandelbrot(t_data *data, int width, int height)
{
    int row = 0;
    int col = 0;
    int max = 200;
    int colors[max];
    int i = 0;
    
    while (i < max)
    {
        // colors[i] = (i + 0x0000FF) / (8.0 * i);
        colors[i] = 400 - (10 * i);
        i++;
    }
    
    while (row < height)
    {
        col = 0;
        while (col < width)
        {
            double c_re = (col - width/2.0)*4.0/width;
            double c_im = (row - height/2.0)*4.0/width;
            double x = 0, y = 0;
            int iteration = 0;
            while (x*x+y*y <= 4 && iteration < max)
            {
                double x_new = x*x - y*y + c_re;
                y = 2*x*y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < max)
            {
                my_mlx_pixel_put(data, col, row, colors[iteration]);
                // my_mlx_pixel_put(data, col, row, 0x000000 + (iteration * 2));
            }
            else
                my_mlx_pixel_put(data, col, row, 0x000000);
            col++;
        }
        row++;
    }
}

int main(void)
{
    void    *mlx;
    t_data  img;
    void    *mlx_win;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
    img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    mandelbrot(&img, WINDOW_WIDTH, WINDOW_HEIGHT);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return 0;
}
