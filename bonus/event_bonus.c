/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:18:55 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/24 19:25:43 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move_arrow_keys(t_fractol *fractol, int keycode)
{
	double	padding;

	padding = 0.1 * (fractol->x_range.max - fractol->x_range.min);
	if (keycode == ESCAPE)
		free_memory(fractol);
	else if (keycode == UP)
	{
		fractol->y_range.min -= padding;
		fractol->y_range.max -= padding;
	}
	else if (keycode == DOWN)
	{
		fractol->y_range.min += padding;
		fractol->y_range.max += padding;
	}
	else if (keycode == LEFT)
	{
		fractol->x_range.min -= padding;
		fractol->x_range.max -= padding;
	}
	else if (keycode == RIGHT)
	{
		fractol->x_range.min += padding;
		fractol->x_range.max += padding;
	}
}

int	key_manager(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	move_arrow_keys(fractol, keycode);
	if (keycode == ONE)
		fractol->color_shift = 1;
	else if (keycode == TWO)
		fractol->color_shift = 12;
	else if (keycode == THREE)
		fractol->color_shift = 3;
	else if (keycode == FOUR)
		fractol->color_shift = 0;
	draw_fractol(fractol);
	return (0);
}

int	mouse_manager(int button, int x, int y, void *param)
{
	t_fractol	*fractol;
	double		mouse_reel;
	double		mouse_img;

	fractol = (t_fractol *)param;
	if (button == Button4)
		fractol->zoom = 0.95;
	else if (button == Button5)
		fractol->zoom = 1.05;
	else
		return (0);
	mouse_reel = (scale_map(x, fractol->x_range, 0, WIDTH));
	mouse_img = (scale_map(y, fractol->y_range, 0, HEIGHT));
	fractol->x_range.min = mouse_reel + (fractol->x_range.min - mouse_reel)
		* fractol->zoom;
	fractol->x_range.max = mouse_reel + (fractol->x_range.max - mouse_reel)
		* fractol->zoom;
	fractol->y_range.min = mouse_img + (fractol->y_range.min - mouse_img)
		* fractol->zoom;
	fractol->y_range.max = mouse_img + (fractol->y_range.max - mouse_img)
		* fractol->zoom;
	draw_fractol(fractol);
	return (0);
}

int	window_manager(void	*param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	free_memory(fractol);
	return (0);
}

void	event_handler(t_fractol *fractol)
{
	mlx_key_hook(fractol->win, key_manager, fractol);
	mlx_mouse_hook(fractol->win, mouse_manager, fractol);
	mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask,
		window_manager, fractol);
}
