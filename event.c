/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:38:09 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/11 00:13:35 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void    free_memory(t_fractol *fractol)
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
    exit(EXIT_SUCCESS);
}
int	key_manager(int keycode,void *param)
{
    t_fractol *fractol = (t_fractol *)param;
    if(keycode == 65307)
    {
        free_memory(fractol);
    }
    return(0);
}

int	mouse_manager(int button, int x, int y, void *param)
{
     t_fractol *fractol = (t_fractol *)param;
    (void)x;
    (void)y;
    if (button == Button5)
    {
        fractol->zoom *=0.95;
    }
    else if (button == Button4)
    {
        fractol->zoom *= 1.05;
    }
    draw_fractol(fractol);
    return(0);
}

int 	window_manager(void *param)
{
    
     t_fractol *fractol = (t_fractol *)param;
        free_memory(fractol);
    
        return(0);
    
}

void event_handler(t_fractol *fractol)
{

	mlx_hook(fractol->win, KeyPress, KeyPressMask, key_manager, fractol);
    mlx_hook(fractol->win, ButtonPress, ButtonPressMask, mouse_manager, fractol);
    mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, window_manager, fractol);


}
