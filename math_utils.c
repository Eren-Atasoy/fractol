#include "fractol.h"

double scale_map(double value, t_range new_range, double old_min,double old_max)
{
 return	((value - old_min) / (old_max - old_min) 
 * (new_range.max - new_range.min) + new_range.min);
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



static long parse_integer(char **str)
{
    long sum = 0;

	
	while(**str)
	{
		if(!(**str >= '0' && **str <= '9') && **str != '.' && **str != '-' && **str != '+')
		{
			error_handler(ERROR_MESSAGE);
		}
		else if(**str >= '0' && **str <= '9')
		{
        	sum = sum * 10 + (**str - '0');
		}
		else if(**str == '.')
			return (sum);
		else if(**str == '-')
			error_handler(ERROR_MESSAGE);
		else if(**str == '+')
			error_handler(ERROR_MESSAGE);

		 (*str)++;
	}
	return (sum);
}

static double parse_fraction(char **str)
{
    double division = 0.0;
    double divisor = 10.0;

    if (**str == '.')
    {
        (*str)++;
		while(**str)
		{
			if(!(**str >= '0' && **str <= '9') && **str != '.' && **str != '-' && **str != '+')
			{
				error_handler(ERROR_MESSAGE);
			}
			else if(**str == '.' || **str == '-' || **str == '+')
				error_handler(ERROR_MESSAGE);

			else if(**str >= '0' && **str <= '9')
			{
				division += (**str - '0') / divisor;
				divisor *= 10;

			}
			(*str)++;
		}
	}
    return (division);
}

double	ft_atof(char *nptr)
{
	int		sign;
	int		result;

	sign = 1;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	result = parse_integer(&nptr);
	return ((double)((result)+
	 parse_fraction(&nptr)) * sign);                    
}
