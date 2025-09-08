
#include "fractol.h"

 void error_handler(void)
{
	perror("Error: Memory allocation failed.");
	exit(EXIT_FAILURE);
}

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