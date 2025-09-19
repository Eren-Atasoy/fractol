/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 02:41:05 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/19 02:47:37 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_gradient_color(double iter, int max_iter, int type)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		band_size;

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
		band_size = 20;
		band = (int)iter % band_size;
		r = (band * 8) % 256;
		g = (band * 4) % 256;
		b = (band * 12) % 256;
		return ((r << 16) | (g << 8) | b);
	}
	return (0);
}
