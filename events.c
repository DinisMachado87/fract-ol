/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:04 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/23 19:46:36 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	recenter_img(int x, int y, t_frctl *fl)
{
	x = (x - (RES_WIDTH / 2));
	y = (y - (RES_HIGHT / 2));
	fl->x_min = scale_pixel(x, RES_WIDTH, fl->x_width, fl->x_min);
	fl->y_min = scale_pixel(y, RES_HIGHT, fl->y_width, fl->y_min);
}

int	render_zoom(t_frctl *fl, int quadratic)
{
	init_scale_image(fl);
	render_fractal(fl, quadratic);
	fl->zoom_to_update = 0;
	return (0);
}

int	handle_mouse(int mouse_move, int x, int y, t_frctl *fl)
{
	recenter_img(x, y, fl);
	if (mouse_move == 5)
		fl->zoom *= 1.05;
	else if (mouse_move == 4)
		fl->zoom *= 0.95;
	else
		return (-1);
	if (fl->zoom_to_update == 10)
		return (render_zoom(fl, 1));
	else
		fl->zoom_to_update++;
	return (0);
}

int	handle_keys(int keycode, t_frctl *fl)
{
	if (keycode == 65307)
		return (close_all(fl));
	else if (keycode == 65361)
		fl->x_offset -= fl->x_width / 5;
	else if (keycode == 65363)
		fl->x_offset += fl->x_width / 5;
	else if (keycode == 65362)
		fl->y_offset -= fl->y_width / 5;
	else if (keycode == 65364)
		fl->y_offset += fl->y_width / 5;
	init_scale_image(fl);
	render_fractal(fl, 1);
	return (-1);
}

int	close_window(int keycode, t_frctl *fl)
{
	(void)keycode;
	return (close_all(fl));
}
