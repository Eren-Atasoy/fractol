#include "fractol.h"



void	init_window(void)
{
	t_fractol fractol;


	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return ;

    
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fract-ol");

	if (!fractol.win)
	{
		mlx_destroy_display(fractol.mlx);
		free(fractol.mlx);
		error_handler();	
	}

	
    draw_fractol(&fractol);
	
    event_handler(&fractol);
	mlx_loop(fractol.mlx);
}

