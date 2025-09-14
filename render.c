#include "fractol.h"
void draw_fractol(t_fractol *fractol)
{

    char	*line;
	int i = 0;
	int j = 0;
	
	fractol->canvas.addr = mlx_get_data_addr(fractol->canvas.img, &fractol->canvas.bpp, &fractol->canvas.size_line, &fractol->canvas.endian);
	
	while(i < HEIGHT)
	{
		line = fractol->canvas.addr + (i * fractol->canvas.size_line);
		while(j < WIDTH)
		{
			if(fractol->type_of_fractal == 1)
			{
				render_mandelbrot(j,i,fractol,line);
			}
			else if(fractol->type_of_fractal == 2)
			{
				render_julia(j,i,fractol,line);
			}	

			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(fractol->mlx,fractol->win, fractol->canvas.img, 0, 0);
}
 void    render_mandelbrot(int x, int y,t_fractol *fractol,char *line)
{
	t_complex z;
	t_complex c;
	
	int i;
	
	i = 0;
	
	z.re = 0.0;
	z.img = 0.0;

	c.re = (scale_map(x, fractol->x_range, 0, WIDTH) * fractol-> zoom);
	c.img = (scale_map(y, fractol->y_range, 0, HEIGHT) * fractol -> zoom);

	while(i < fractol->max_iteration )
	{
		z = iterate_formul(z,c);
		if((z.re * z.re) + (z.img * z.img) > fractol->out_of_value)
		{
			double zn = sqrt(z.re*z.re + z.img*z.img);
			double nu = log(log(zn) / log(2)) / log(2);
			double smooth_iter = i + 1 - nu;

			 fractol->color = get_gradient_color(smooth_iter, fractol->max_iteration);
    		line = fractol->canvas.addr + (y * fractol->canvas.size_line);
			*(unsigned int *)(line + x * (fractol->canvas.bpp / 8)) = fractol->color;
			return;
		}
		i++;
	}
    line = fractol->canvas.addr + (y * fractol->canvas.size_line );
    *(unsigned int *)(line + x * (fractol->canvas.bpp / 8)) = BLACK;
}

void    render_julia(int x, int y,t_fractol *fractol,char *line)
{
	t_complex z;
	t_complex c;
	
	int i;
	
	i = 0;

	z.re = (scale_map(x, fractol->x_range, 0, WIDTH) * fractol-> zoom);
	z.img = (scale_map(y, fractol->y_range, 0, HEIGHT) * fractol-> zoom);
	
	c.re = fractol->julia_arg.re;
	c.img = fractol->julia_arg.img;

	while(i < fractol->max_iteration )
	{
		z = iterate_formul(z,c);
		// printf("iterated z.re^2 + z.img^2: %f\n", (z.re * z.re) + (z.img * z.img));
		if((z.re * z.re) + (z.img * z.img) > fractol->out_of_value)
		{
			double zn = sqrt(z.re*z.re + z.img*z.img);
			double nu = log(log(zn) / log(2)) / log(2);
			double smooth_iter = i + 1 - nu;

			 fractol->color = get_gradient_color(smooth_iter, fractol->max_iteration);
    		line = fractol->canvas.addr + (y * fractol->canvas.size_line);
			*(unsigned int *)(line + x * (fractol->canvas.bpp / 8)) = fractol->color;
			return;
		}
		i++;
	}
    line = fractol->canvas.addr + (y * fractol->canvas.size_line );
    *(unsigned int *)(line + x * (fractol->canvas.bpp / 8)) = BLACK;
}
