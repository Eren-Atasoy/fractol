/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:19:08 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/20 18:19:10 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	fractol.type_of_fractal = check_args(argc, argv[1]);
	if (!fractol.type_of_fractal)
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (1);
	}
	init_window(&fractol, argv);
	draw_fractol(&fractol);
	event_handler(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
