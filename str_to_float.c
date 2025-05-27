/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:40:49 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/27 16:04:40 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	str_to_decimals(char *str)
{
	float	decimals;
	float	factor;

	decimals = 0.00;
	factor = 10.00;
	while (*str >= '0' && *str <= '9')
	{
		decimals += (*str - '0') / factor;
		str++;
		factor *= 10.00;
	}
	return (decimals);
}

float	str_to_float(const char *nptr)
{
	int		minus;
	float	result;

	minus = 1;
	result = 0.0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		minus = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.' && *(nptr + 1) && *(nptr + 1) >= '0' && *(nptr + 1) <= '9')
		result += str_to_decimals((char *)nptr + 1);
	return (minus * result);
}
