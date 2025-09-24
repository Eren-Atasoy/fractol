/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:18:44 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/20 20:07:21 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_gradient_color(double iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = iter / max_iter;
	r = (int)(12 * (1 - t) * t * t * t * 255);
	g = (int)(12 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(6 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((b << 16) | (r << 8) | g);
}
