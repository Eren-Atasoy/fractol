/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:01:01 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/19 04:02:27 by eratasoy         ###   ########.fr       */
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
