/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:17:04 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/20 18:17:53 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_map(double value, t_range new_range, double old_min,
		double old_max)
{
	return ((value - old_min) / (old_max - old_min)
		* (new_range.max - new_range.min) + new_range.min);
}

t_complex	iterate_formul(t_complex z, t_complex c)
{
	t_complex	z_square;
	t_complex	result;

	z_square.re = (z.re * z.re) - (z.img * z.img);
	z_square.img = 2 * (z.re * z.img);
	result.re = z_square.re + c.re;
	result.img = z_square.img + c.img;
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
