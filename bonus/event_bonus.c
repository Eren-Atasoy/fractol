/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:18:55 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/24 04:18:58 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	free_memory(t_fractol	*fractol)
{
	if (fractol->canvas.img)
		mlx_destroy_image(fractol->mlx, fractol->canvas.img);
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(EXIT_FAILURE);
}

int	key_manager(int keycode, void *param)
{
	t_fractol	*fractol;
	fractol = (t_fractol *)param;
	
	double padding = 0.1 * (fractol->x_range.max - fractol->x_range.min);
	
	if (keycode == ESCAPE)
		free_memory(fractol);
	else if(keycode == UP)
	{
		fractol->y_range.min -= padding;
		fractol->y_range.max -= padding; 
	}
	else if(keycode == DOWN)
	{
		fractol->y_range.min += padding;
		fractol->y_range.max += padding; 
	}
	else if(keycode == LEFT)
	{
		fractol->x_range.min -= padding;
		fractol->x_range.max -= padding; 
	}
	else if(keycode == RIGHT)
	{
		fractol->x_range.min += padding;
		fractol->x_range.max += padding; 
	}
		draw_fractol(fractol);
	return (0);
}

int	mouse_manager(int button, int x, int y, void *param)
{
	t_fractol	*fractol;
	double mouse_reel;
	double mouse_img;
	double new_width;
	double new_height;

	fractol = (t_fractol *)param;
 	

	if (button == Button4)
	{
		fractol->zoom = 0.95;
	}
	else if (button == Button5)
	{
		fractol->zoom = 1.05;
	}
	else
	{
		return (0);
	}
	
	mouse_reel = (scale_map(x, fractol->x_range, 0, WIDTH));
	mouse_img = (scale_map(y, fractol->y_range, 0, HEIGHT));
		
	new_width = (fractol->x_range.max - fractol->x_range.min ) * fractol->zoom;
	new_height = (fractol->y_range.max - fractol->y_range.min ) * fractol->zoom;
		
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
