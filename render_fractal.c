/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:08:51 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/28 23:50:36 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Squaring a Complex Number z = a + bi
Starting with z = a + bi (where a is the real part, b is the imaginary part)
We want to find z² = (a + bi)²
Step 1: Multiply the expression by itself using the distributive property.
(a + bi)(a + bi)
Step 2: Multiply each term in the first bracket with each term in the second
bracket. (a + bi)(a + bi) = a × a + a × bi + bi × a + bi × bi Step 3: Simplify
each multiplication. = a² + abi + abi + bi² Step 4: Combine like terms. = a² +
abi + bi² Step 5: Apply the rule i² = -1 to simplify bi². bi² = b × i² = b × (-1
 = -b Step 6: Substitute this back into our expression. a² + 2abi + bi² = a² +
abi + (-b) = a² + 2abi - b² Step 7: Rearrange to group real and imaginary
parts. = (a² - b²) + (2ab)i So the result is:

Real part of z²: a² - b²
Imaginary part of z²: 2ab
*/

static inline t_c	square_complex(t_c z)
{
	t_c	result;

	result.r_x = z.r_x * z.r_x - z.i_y * z.i_y;
	result.i_y = 2.0 * z.r_x * z.i_y;
	return (result);
}

double	scale_pixel(int pixel_coordinate, int axis, double range, double min)
{
	return (((double)pixel_coordinate / (double)(axis - 1)) * range + min);
}

static int	color_calc(int iterations, t_frctl *fl)
{
	int	rgb_a;
	int	rgb_b;
	int	rgb_c;

	iterations = iterations * 255 / (MAX_ITERATIONS * fl->fractal
			* (fl->iter_ratio + 1));
	rgb_a = 255 - iterations;
	rgb_b = iterations;
	rgb_c = 0;
	if (iterations < (255 / 3))
		return ((255 << 24) | (rgb_c << 16) | (rgb_b << 8) | rgb_a);
	else if (iterations < ((255 / 3) * 2))
		return ((255 << 24) | (rgb_b << 16) | (rgb_a << 8) | rgb_c);
	else
		return ((255 << 24) | (rgb_a << 16) | (rgb_c << 8) | rgb_b);
}

static void	color_pixel(t_c px, t_frctl *fl, int color, int quadratic)
{
	int	px_position;
	int	px_pos_nxt_line;

	px_position = (px.i_y * fl->img.line_len) + (px.r_x * (fl->img.bpp / 8.0));
	*(unsigned int *)(fl->img.addr + px_position) = color;
	px_pos_nxt_line = 0;
	if (quadratic)
	{
		if ((px.i_y + 1) < RES_HIGHT)
		{
			px_pos_nxt_line = ((px.i_y + 1) * fl->img.line_len) + (px.r_x
					* (fl->img.bpp / 8.0));
			*(unsigned int *)(fl->img.addr + px_pos_nxt_line) = color;
		}
		if (px.r_x + 1 < RES_WIDTH)
		{
			px_position = (px.i_y * fl->img.line_len) + ((px.r_x + 1)
					* (fl->img.bpp / 8.0));
			*(unsigned int *)(fl->img.addr + px_position) = color;
			if ((px.i_y + 1) < RES_HIGHT)
			{
				px_pos_nxt_line = ((px.i_y + 1) * fl->img.line_len) + ((px.r_x
							+ 1) * (fl->img.bpp / 8.0));
				*(unsigned int *)(fl->img.addr + px_pos_nxt_line) = color;
			}
		}
	}
}

inline static void	fractal_assignement(t_c px, t_c *c, t_c *z, t_frctl *fl)
{
	if (fl->fractal == MANDELBROT)
	{
		c->r_x = scale_pixel(px.r_x, RES_WIDTH, fl->x_width, fl->x_min);
		c->i_y = scale_pixel(px.i_y, RES_HIGHT, fl->y_width, fl->y_min);
		*z = fl->c;
	}
	else if (fl->fractal == JULIA)
	{
		z->r_x = scale_pixel(px.r_x, RES_WIDTH, fl->x_width, fl->x_min);
		z->i_y = scale_pixel(px.i_y, RES_HIGHT, fl->y_width, fl->y_min);
		*c = fl->c;
	}
}

static void	fractal_calc(t_c px, t_frctl *fl, int quadratic)
{
	t_c	z;
	t_c	c;
	int	i;
	t_c	first_z;

	i = (MAX_ITERATIONS * fl->fractal * (fl->iter_ratio + 1));
	fractal_assignement(px, &c, &z, fl);
	while (i-- >= 0)
	{
		z = square_complex(z);
		z.r_x = z.r_x + c.r_x;
		z.i_y = z.i_y + c.i_y;
		if ((z.r_x * z.r_x + z.i_y * z.i_y) > 4.0)
			return (color_pixel(px, fl, color_calc(i, fl), quadratic));
		if ((i == 7) || (i == 20))
		{
			first_z.r_x = z.r_x;
			first_z.i_y = z.i_y;
		}
		if ((z.i_y == first_z.i_y) && (z.r_x == first_z.r_x))
			return (color_pixel(px, fl, BLACK, quadratic));
	}
	return (color_pixel(px, fl, BLACK, quadratic));
}

void	render_fractal(t_frctl *fl, int quadratic)
{
	t_c	px;
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < RES_HIGHT)
	{
		x = 0;
		while (x < RES_WIDTH)
		{
			px.i_y = (double)y;
			px.r_x = (double)x;
			fractal_calc(px, fl, quadratic);
			x += (1 + quadratic);
		}
		y += (1 + quadratic);
	}
	mlx_put_image_to_window(fl->mlx, fl->mlx_win, fl->img.img, 0, 0);
}
