/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:30:41 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/21 17:57:54 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Squaring a Complex Number z = a + bi
Starting with z = a + bi (where a is the real part, b is the imaginary part)
We want to find z² = (a + bi)²
Step 1: Multiply the expression by itself using the distributive property.
(a + bi)(a + bi)
Step 2: Multiply each term in the first bracket with each term in the second bracket.
(a + bi)(a + bi) = a × a + a × bi + bi × a + bi × bi
Step 3: Simplify each multiplication.
= a² + abi + abi + bi²
Step 4: Combine like terms.
= a² + 2abi + bi²
Step 5: Apply the rule i² = -1 to simplify bi².
bi² = b × i² = b × (-1) = -b
Step 6: Substitute this back into our expression.
a² + 2abi + bi² = a² + 2abi + (-b) = a² + 2abi - b²
Step 7: Rearrange to group real and imaginary parts.
= (a² - b²) + (2ab)i
So the result is:

Real part of z²: a² - b²
Imaginary part of z²: 2ab
*/

double	scale_pixel(int pixel_coordinate, int axis)
{
	return (((double)axis / (double)pixel_coordinate) * 4.0 - 2.0);
}

t_c	square_complex(t_c z)
{
	t_c	result;

	result.r_x = z.r_x * z.r_x - z.i_y * z.i_y;
	result.i_y = 2.0 * z.r_x * z.i_y;
	return (result);
}

double	mandelbrot_calc(t_c px)
{
	t_c	z;
	int	i;
	t_c	first_z;

	i = N_ITERATIONS;
	z.r_x = 0.0;
	z.i_y = 0.0;
	while (i-- >= 0)
	{
		z = square_complex(z);
		z.r_x = z.r_x + px.r_x;
		z.i_y = z.i_y + px.i_y;
		if ((z.r_x * z.r_x + z.i_y * z.i_y) > 4.0)
			return (color_unbound(px, i));
		if ((i == 2) || (i == 6) || (i == 12) || (i == 15))
		{
			first_z.r_x = z.r_x;
			first_z.i_y = z.i_y;
		}
		if ((z.i_y == first_z.i_y) && (z.r_x == first_z.r_x))
			return (color_bound(px));
	}
	return (color_bound(px));
}

void	render_fractal(t_frctl *fl)
{
	int	i_width;
	int	i_height;

	i_width = 0;
	i_height = 0;
	while (i_height < RES_HIGHT)
	{
		while (i_width < RES_WIDTH)
		{
			i_width++;
		}
		i_height++;
	}
}
