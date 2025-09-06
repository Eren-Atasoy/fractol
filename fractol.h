#ifndef FRACTOL_H
# define FRACTOL_H


# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <libft.h>

typedef struct s_complex
{
    double re;
    double img;
}   t_complex;


# define RED        0xFF0000
# define GREEN      0x00FF00
# define BLUE       0x0000FF
# define WHITE      0xFFFFFF
# define BLACK      0x000000
# define PURPLE 0x800080

# define ERROR_MESSAGE \
"Error: Invalid parameter. Please check your input.\n" \
"\"./fractol mandelbrot\"\n" \
"or\n" \
"\"./fractol julia <reel> <imaginary>\"\n"
# define HEIGHT 1080
# define WIDTH 1920

#endif
