#ifndef FRACTOL_H
# define FRACTOL_H


# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <libft.h>
# include <math.h>
typedef struct s_complex
{
    double re;
    double img;
}   t_complex;


#define RED     0xFF4D6D   // pembe-kırmızı
#define GREEN   0x7CFF6B   // parlak limon-yeşil
#define BLUE    0x4DB8FF   // parlak gök-mavisi
#define WHITE   0xFFFFFF
#define BLACK   0x000000
#define PURPLE  0xB24DFF   // neon mor


# define ERROR_MESSAGE \
"Error: Invalid parameter. Please check your input.\n" \
"\"./fractol mandelbrot\"\n" \
"or\n" \
"\"./fractol julia <reel> <imaginary>\"\n"
 # define HEIGHT 1080
# define WIDTH 1920

#endif
