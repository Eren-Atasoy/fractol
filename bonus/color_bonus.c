/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:18:44 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/24 19:17:53 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_gradient_color(double iter, int max_iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = iter / max_iter;
	if (shift == 0)
	{
		r = (int)(15 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		return ((b << 16) | (r << 8) | g);
	}
	else
	{
		r = (int)(15 * ((1 - t) * shift) * t * t * t * 255);
		g = (int)(15 * ((1 - t) * shift / 2) * (1 - t) * t * t * 255);
		b = (int)(9 * ((1 - t) * shift / 4) * (1 - t) * (1 - t) * t * 255);
		return ((b << 16) | (r << 8) | g);
	}
}
