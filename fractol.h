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


typedef struct s_complex
{
    double re;
    double img;
}   t_complex;

typedef struct s_canvas
{
    
    void	*img;
	char	*addr;
	int     bpp;
	int     size_line;
	int     endian;
}   t_canvas;
typedef struct s_fractol
{
    void    *mlx;
    void    *win;
    t_canvas    canvas;
    int     color;
    double out_of_value;
	int max_iteration;
    int         type_of_fractal;
    double      zoom;

    //double      axis_x;
    //double      axis_y;
}   t_fractol;


void    init_window(void);

void draw_fractol(t_fractol *fractol);
 void    render_pixel(int x, int y,t_fractol *fractol);

double  scale_map(double value, double new_min, double new_max,
                  double old_min, double old_max);
t_complex iterate_formul(t_complex z, t_complex c);
 void error_handler(void);


int     get_gradient_color(double iter, int max_iter);


void event_handler(t_fractol *fractol);

int     check_args(int argc, char *argv);
void    free_memory(t_fractol *fractol);


int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_putstr_fd(char *s, int fd);


#endif
