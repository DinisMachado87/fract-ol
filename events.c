/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:04 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/30 21:42:31 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_count(t_frctl *fl)
{
	if (fl->zoom_to_update == 10)
	{
		render_fractal(fl, 1);
		fl->zoom_to_update = 0;
	}
	else
		fl->zoom_to_update++;
	return (0);
}

static void	zoom_and_recenter(int x, int y, t_frctl *fl, char zoom)
{
	fl->x_offset = fl->x_min + ((double)x / RES_WIDTH) * fl->x_width;
	fl->y_offset = fl->y_min + ((double)y / RES_HIGHT) * fl->y_width;
	if (zoom == '+')
	{
		fl->zoom *= 0.95;
		fl->iter_ratio += 0.05;
	}
	else
	{
		fl->zoom *= 1.05;
		fl->iter_ratio -= 0.04;
	}
	fl->x_width = 4.0 * fl->zoom;
	fl->y_width = scale_y_px_to_math(fl);
	fl->x_min = fl->x_offset - ((double)x / RES_WIDTH) * fl->x_width;
	fl->y_min = fl->y_offset - ((double)y / RES_HIGHT) * fl->y_width;
}

int	handle_mouse(int mouse_move, int x, int y, t_frctl *fl)
{
	if (mouse_move == 4)
		zoom_and_recenter(x, y, fl, '+');
	else if (mouse_move == 5)
		zoom_and_recenter(x, y, fl, '-');
	else
		return (-1);
	return (render_count(fl));
}

int	handle_mouse_motion(int x, int y, t_frctl *fl)
{
	float	x_diff;
	float	y_diff;
	float	threshold;

	if (!fl->mouse_coordinates)
		return (0);
	threshold = THRESHOLD * fl->zoom;
	x_diff = fl->c.r_x - scale_pixel(x, RES_WIDTH, fl->x_width, fl->x_min);
	y_diff = fl->c.i_y - scale_pixel(y, RES_HIGHT, fl->y_width, fl->y_min);
	if (x_diff > threshold || x_diff < -threshold || y_diff > threshold
		|| y_diff < -threshold)
	{
		fl->c.r_x = scale_pixel(x, RES_WIDTH, fl->x_width, fl->x_min);
		fl->c.i_y = scale_pixel(y, RES_HIGHT, fl->y_width, fl->y_min);
	}
	return (render_count(fl));
}

int	handle_keys(int keycode, t_frctl *fl)
{
	if (keycode == ESC_KE)
		return (close_all(fl));
	else if (keycode == F_KE && fl->mouse_coordinates)
		fl->mouse_coordinates = 0;
	else if (keycode == F_KE && !fl->mouse_coordinates)
		fl->mouse_coordinates = 1;
	else if (keycode == C_KE)
	{
		if (fl->color == 4)
			fl->color = 0;
		fl->color += 1;
	}
	else if (keycode == A_LEFT)
		fl->x_min -= fl->x_width / 5;
	else if (keycode == A_RIGHT)
		fl->x_min += fl->x_width / 5;
	else if (keycode == A_UP)
		fl->y_min -= fl->y_width / 5;
	else if (keycode == A_DOWN)
		fl->y_min += fl->y_width / 5;
	render_fractal(fl, 0);
	return (-1);
}
