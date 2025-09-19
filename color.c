/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 02:41:05 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/19 05:10:08 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_gradient_color(double iter, int max_iter, int type)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		band;

	t = iter / max_iter;
	if (type == 1)
	{
		t = iter / max_iter;
		r = (int)(12 * (1 - t) * t * t * t * 255);
		g = (int)(12 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(6 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		return ((b << 16) | (r << 8) | g);
	}
	else if (type == 2)
	{
		band = (int)iter % 20;
		r = (band * 8) % 256;
		g = (band * 4) % 256;
		b = (band * 12) % 256;
		return ((r << 16) | (g << 8) | b);
	}
	return (0);
}
