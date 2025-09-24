/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:02:48 by eratasoy          #+#    #+#             */
/*   Updated: 2025/09/20 20:12:03 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long	parse_integer(char **str, int *flag)
{
	long	sum;

	sum = 0;
	while (**str)
	{
		if (!(**str >= '0' && **str <= '9') && **str != '.' && **str != '-'
			&& **str != '+')
		{
			error_handler(ERROR_MESSAGE);
		}
		else if (**str >= '0' && **str <= '9')
		{
			sum = sum * 10 + (**str - '0');
			*flag = 1;
		}
		else if (**str == '.')
			return (sum);
		else if (**str == '-')
			error_handler(ERROR_MESSAGE);
		else if (**str == '+')
			error_handler(ERROR_MESSAGE);
		(*str)++;
	}
	return (sum);
}

static double	parse_fraction(char **str, int *flag)
{
	double	division;
	double	divisor;

	division = 0.0;
	divisor = 10.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str)
		{
			if (!(**str >= '0' && **str <= '9') && **str != '.'
				&& **str != '-' && **str != '+')
				error_handler(ERROR_MESSAGE);
			else if (**str == '.' || **str == '-' || **str == '+')
				error_handler(ERROR_MESSAGE);
			else if (**str >= '0' && **str <= '9')
			{
				division += (**str - '0') / divisor;
				divisor *= 10;
				*flag = 1;
			}
			(*str)++;
		}
	}
	return (division);
}

double	ft_atof(char *nptr)
{
	double		sign;
	double		result;
	double		fraction;
	int			has_number;
	int			i;

	i = 0;
	has_number = 0;
	sign = 1.0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1.0;
		nptr++;
	}
	result = parse_integer(&nptr, &has_number);
	fraction = parse_fraction(&nptr, &has_number);
	if (!has_number)
		error_handler(ERROR_MESSAGE);
	return ((double)((result + fraction) * sign));
}
