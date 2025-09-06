
#include "fractol.h"




static void error_handler(void)
{
	perror("Error: Memory allocation failed.");
	exit(EXIT_FAILURE);
}


double scale_map(double value, double new_min, double new_max, double old_min, double old_max)
{
 return	((value - old_min) / (old_max - old_min) * (new_max - new_min) + new_min);
}

t_complex iterate_formul(t_complex z,t_complex c)
{
	// z^2 + c;
	t_complex z_square;
	t_complex result;

	z_square.re = (z.re * z.re) - (z.img * z.img);
	z_square.img = 2 * (z.re * z.img) ;

	result.re = z_square.re + c.re;
	result.img = z_square.img + c.img;
	return (result);
}


static void    render_pixel(char *addr, int x, int y, int bpp, int size_line)
{
	t_complex z;
	t_complex c;
	char *dst;
	double out_of_value;
	int max_iteration;
	int color;
	int i;
	max_iteration = 1000;
	i = 0;
	out_of_value = 4;
	z.re = 0.0;
	z.img = 0.0;

	c.re = scale_map(x, -2, +2, 0, WIDTH);
	c.img = scale_map(y, +1, -1, 0, HEIGHT);

	while(i < max_iteration )
	{
		z = iterate_formul(z,c);

		if((z.re * z.re) + (z.img * z.img) > out_of_value)
		{
			color = scale_map(i, BLACK, WHITE, 0, max_iteration);
			

    		dst = addr + (y * size_line + x * (bpp / 8));
    		*(unsigned int *)dst = color;
			return;
		}
		++i;
	}
	dst = addr + (y * size_line + x * (bpp / 8));
    		*(unsigned int *)dst = PURPLE;

}

void	init_window(void)
{
	void	*mlx;
	void	*win;

	void	*img;

	char	*addr;
	int     bpp;
	int     size_line;
	int     endian;

	mlx = mlx_init();
	if (!mlx)
		return ;


	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		error_handler();	
	};

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if(!img)
	{
		mlx_destroy_window(mlx,win);
		mlx_destroy_display(mlx);
		free(mlx);
		error_handler();
	}
	addr = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	int i = 0;
	int j = 0;
	while(i < HEIGHT)
	{
		while(j < WIDTH)
		{
			render_pixel(addr,j,i,bpp,size_line);
			
			j++;
		}
		j = 0;
		i++;
	}

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}


/*void render_fractal()
{



}	*/
int check_args(int argc, char *argv)
{
	if(argc == 2  && !ft_strncmp(argv,"mandelbrot",10))
	{
		return (1);
	}
	else if(argc == 4 && !ft_strncmp(argv,"julia",5) )
	{
		return (1);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
		return(0);
	}
}

int	main(int argc, char **argv)
{

	// mandelbrot , julia 
	if(check_args(argc, argv[1]))
	{
		init_window();
		//render_fractal();
	}
	return (0);
}
