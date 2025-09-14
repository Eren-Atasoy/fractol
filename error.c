
#include "fractol.h"

 void error_handler(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int check_args(int argc, char *argv)
{
	if(argc == 2  && !ft_strncmp(argv,"mandelbrot",10))
	{
		return (1);
	}
	else if((argc == 4 || argc == 2 ) && !ft_strncmp(argv,"julia",5))
	{
		return (2);
	}

		return(0);
	
}