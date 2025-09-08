
#include "fractol.h"


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
