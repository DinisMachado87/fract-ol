/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:27:44 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/30 17:30:08 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_calc(int iterations, t_frctl *fl)
{
	int	rgb_a;
	int	rgb_b;
	int	rgb_c;

	iterations = iterations * 255 / (MAX_ITERATIONS * (fl->iter_ratio + 1));
	rgb_a = 255 - iterations;
	rgb_b = iterations;
	rgb_c = 0;
	if (fl->color == 1)
	{
		if (iterations < (255 / 3))
			return ((255 << 24) | (rgb_c << 16) | (rgb_b << 8) | rgb_a);
		else if (iterations < ((255 / 3) * 2))
			return ((255 << 24) | (rgb_b << 16) | (rgb_a << 8) | rgb_c);
		else
			return ((255 << 24) | (rgb_a << 16) | (rgb_c << 8) | rgb_b);
	}
	if (fl->color == 2)
		return ((255 << 24) | (rgb_c << 16) | (rgb_b << 8) | rgb_a);
	if (fl->color == 3)
		return ((255 << 24) | (rgb_b << 16) | (rgb_a << 8) | rgb_c);
	else
		return ((255 << 24) | (rgb_a << 16) | (rgb_c << 8) | rgb_b);
}
