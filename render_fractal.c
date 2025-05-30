/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:08:51 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/30 17:36:15 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_info(t_frctl *fl)
{
	if (fl->fractal == MANDELBROT)
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 20, 0x78AB46, M_TITLE);
	else
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 20, 0x78AB46, J_TITLE);
	if (fl->color == BLUE)
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 40, 0x78AB46, BLUE_STR);
	else if (fl->color == GREEN)
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 40, 0x78AB46, GREEN_STR);
	else if (fl->color == RED)
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 40, 0x78AB46, RED_STR);
	else
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 40, 0x78AB46, TRIPPY_STR);
	if (fl->mouse_coordinates)
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 60, 0x78AB46, ON_FIRE);
	else
		mlx_string_put(fl->mlx, fl->mlx_win, 20, 60, 0x78AB46, OFF_FIRE);
	mlx_string_put(fl->mlx, fl->mlx_win, 20, 80, 0x78AB46, ARROWS);
	mlx_string_put(fl->mlx, fl->mlx_win, 20, 100, 0x78AB46, WHEEL);
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
	print_info(fl);
}
