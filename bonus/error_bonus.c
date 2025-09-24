/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:18:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/23 23:14:26 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	error_handler(char	*message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	check_args(int argc, char *argv)
{
	if (argc == 2 && !ft_strncmp(argv, "mandelbrot", 11))
		return (1);
	else if ((argc == 4 || argc == 2) && !ft_strncmp(argv, "julia", 6))
		return (2);
	else if (argc == 2 && !ft_strncmp(argv, "tricorn", 8))
		return (3);
	return (0);
}
