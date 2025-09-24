/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:43:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/24 01:52:40 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define BLACK 0x000000

# define HEIGHT 600
# define WIDTH 800

# define ESCAPE 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363


# define ERROR "Error: Unexpected failure occurred"

# define ERROR_MESSAGE "Error: Invalid parameter. Please check your input.\n\
./fractol mandelbrot\n\
or\n\
./fractol julia <reel> <imaginary>\n\
or\n\
./fractol tricorn\n\
Recommended Julia parameters:\n\
julia -0.1 0\n\
julia -0.58 -0.55\n\
julia -0.84 0.22\n"

typedef struct s_complex
{
	double	re;
	double	img;
}	t_complex;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_canvas
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_canvas;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_canvas	canvas;
	t_complex	julia_arg;
	t_range		x_range;
	t_range		y_range;
	int			color;
	double		out_of_value;
	int			max_iteration;
	int			type_of_fractal;
	double		zoom;
	double		axis_x;
	double		axis_y;
}	t_fractol;

void		init_window(t_fractol *fractol, char **argv);
void		draw_fractol(t_fractol *fractol);
void		render_mandelbrot(int x, int y, t_fractol *fractol);
void		render_julia(int x, int y, t_fractol *fractol);
void		render_tricorn(int x, int y, t_fractol *fractol);
double		scale_map(double value, t_range new_range,
				double old_min, double old_max);
t_complex	iterate_formul(t_complex z, t_complex c, int is_tricorn);
void		error_handler(char *message);
int			get_gradient_color(double iter, int max_iter);
void		event_handler(t_fractol *fractol);
int			check_args(int argc, char *argv);
void		free_memory(t_fractol *fractol);
double		ft_atof(char *nptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);

#endif
