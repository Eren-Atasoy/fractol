#include "fractol.h"

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