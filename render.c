#include "fractol.h"
void draw_fractol(t_fractol *fractol)
{

    
	if(!fractol->canvas.img)
	{
		mlx_destroy_window(fractol->mlx,fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		error_handler();
	}

    fractol->canvas.addr = mlx_get_data_addr(fractol->canvas.img, &fractol->canvas.bpp, &fractol->canvas.size_line, &fractol->canvas.endian);
	int i = 0;
	int j = 0;
	while(i < HEIGHT)
	{
		while(j < WIDTH)
		{
			render_pixel(j,i,fractol);
			
			j++;
		}
		j = 0;
		i++;
	}

	mlx_put_image_to_window(fractol->mlx,fractol->win, fractol->canvas.img, 0, 0);
}
 void    render_pixel(int x, int y,t_fractol *fractol)
{
	t_complex z;
	t_complex c;
	char *tmp;
	int i;
	
	i = 0;
	z.re = 0.0;
	z.img = 0.0;
    fractol->max_iteration = 100;

	c.re = (scale_map(x, -2, +2, 0, WIDTH) * fractol-> zoom);
	c.img = (scale_map(y, +2, -2, 0, HEIGHT) * fractol -> zoom);
	while(i < fractol->max_iteration )
	{
		z = iterate_formul(z,c);
		if((z.re * z.re) + (z.img * z.img) > fractol->out_of_value)
		{
			double zn = sqrt(z.re*z.re + z.img*z.img);
			double nu = log(log(zn) / log(2)) / log(2);
			double smooth_iter = i + 1 - nu;

			 fractol->color = get_gradient_color(smooth_iter, fractol->max_iteration);
    		tmp = fractol->canvas.addr + (y * fractol->canvas.size_line + x * (fractol->canvas.bpp / 8));
    		*(unsigned int *)tmp = fractol->color;
			return;
		}
		i++;
	}
    tmp = fractol->canvas.addr + (y * fractol->canvas.size_line + x * (fractol->canvas.bpp / 8));
    *(unsigned int *)tmp = BLACK ;
}

