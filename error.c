/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 03:56:26 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/19 04:00:33 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handler(char	*message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	check_args(int argc, char *argv)
{
	if (argc == 2 && !ft_strncmp(argv, "mandelbrot", 10))
		return (1);
	else if ((argc == 4 || argc == 2) &&!ft_strncmp(argv, "julia", 5))
		return (2);
	return (0);
}
