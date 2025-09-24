/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:17:52 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/24 15:56:20 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw_fractol(t_fractol *fractol)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	fractol->canvas.addr = mlx_get_data_addr(fractol->canvas.img,
			&fractol->canvas.bpp, &fractol->canvas.size_line,
			&fractol->canvas.endian);
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (fractol->type_of_fractal == 1)
				render_mandelbrot(x, y, fractol);
			else if (fractol->type_of_fractal == 2)
				render_julia(x, y, fractol);
			else if (fractol->type_of_fractal == 3)
				render_tricorn(x, y, fractol);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->canvas.img, 0, 0);
}

static void	draw_pixel(t_fractol *fractol, int x, int y)
{
	char	*row_start;

	row_start = fractol->canvas.addr + (y * fractol->canvas.size_line);
	*(unsigned int *)(row_start + x
			* (fractol->canvas.bpp / 8)) = fractol->color;
}

void	render_mandelbrot(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.re = 0.0;
	z.img = 0.0;
	c.re = (scale_map(x, fractol->x_range, 0, WIDTH));
	c.img = (scale_map(y, fractol->y_range, 0, HEIGHT));
	while (i < fractol->max_iteration)
	{
		z = iterate_formul(z, c, fractol->type_of_fractal);
		if ((z.re * z.re) + (z.img * z.img) > fractol->out_of_value)
		{
			fractol->color = get_gradient_color(i,
					fractol->max_iteration, fractol->color_shift);
			draw_pixel(fractol, x, y);
			return ;
		}
		i++;
	}
	fractol->color = BLACK;
	draw_pixel(fractol, x, y);
}

void	render_julia(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.re = (scale_map(x, fractol->x_range, 0, WIDTH));
	z.img = (scale_map(y, fractol->y_range, 0, HEIGHT));
	c.re = fractol->julia_arg.re;
	c.img = fractol->julia_arg.img;
	while (i < fractol->max_iteration)
	{
		z = iterate_formul(z, c, fractol->type_of_fractal);
		if ((z.re * z.re) + (z.img * z.img) > fractol->out_of_value)
		{
			fractol->color = get_gradient_color(i,
					fractol->max_iteration, fractol->color_shift);
			draw_pixel(fractol, x, y);
			return ;
		}
		i++;
	}
	fractol->color = BLACK;
	draw_pixel(fractol, x, y);
}

void	render_tricorn(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.re = 0.0;
	z.img = 0.0;
	c.re = (scale_map(x, fractol->x_range, 0, WIDTH));
	c.img = (scale_map(y, fractol->y_range, 0, HEIGHT));
	while (i < fractol->max_iteration)
	{
		z = iterate_formul(z, c, fractol->type_of_fractal);
		if ((z.re * z.re) + (z.img * z.img) > fractol->out_of_value)
		{
			fractol->color = get_gradient_color(i,
					fractol->max_iteration, fractol->color_shift);
			draw_pixel(fractol, x, y);
			return ;
		}
		i++;
	}
	fractol->color = BLACK;
	draw_pixel(fractol, x, y);
}
