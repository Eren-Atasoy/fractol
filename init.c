/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 03:48:28 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/19 03:55:58 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol_data(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->color = 0xFFFFFF;
	fractol->out_of_value = 4.0;
	fractol->max_iteration = 50;
	fractol->zoom = 1.0;
	fractol->canvas.addr = NULL;
	fractol->canvas.bpp = 0;
	fractol->canvas.size_line = 0;
	fractol->canvas.endian = 0;
	if (fractol->type_of_fractal == 1)
	{
		fractol->x_range.min = -2.0;
		fractol->x_range.max = 2.0;
		fractol->y_range.min = -1.5;
		fractol->y_range.max = 1.5;
	}
	else if (fractol->type_of_fractal == 2)
	{
		fractol->x_range.min = -2.0;
		fractol->x_range.max = 2.0;
		fractol->y_range.min = -1.5;
		fractol->y_range.max = 1.5;
	}
}

void	init_window(t_fractol *fractol, char **argv)
{
	init_fractol_data(fractol);
	if (argv[2] && argv[3])
	{
		fractol->julia_arg.re = ft_atof(argv[2]);
		fractol->julia_arg.img = ft_atof(argv[3]);
	}
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		fractol->julia_arg.re = -0.7;
		fractol->julia_arg.img = 0.27015;
	}
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		error_handler(ERROR);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol->win)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		error_handler(ERROR);
	}
	fractol->canvas.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->canvas.img)
		error_handler(ERROR);
}
