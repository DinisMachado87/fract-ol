/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:04 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/27 11:54:25 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_and_recenter(int x, int y, t_frctl *fl, char zoom)
{
	fl->x_offset = fl->x_min + ((double)x / RES_WIDTH) * fl->x_width;
	fl->y_offset = fl->y_min + ((double)y / RES_HIGHT) * fl->y_width;
	if (zoom == '+')
	{
		fl->zoom *= 0.95;
		fl->iterations_ratio += 0.05;
	}
	else
	{
		fl->zoom *= 1.05;
		fl->iterations_ratio -= 0.05;
	}
	fl->x_width = 5.0 * fl->zoom;
	fl->y_width = scale_y_px_to_math(fl);
	fl->x_min = fl->x_offset - ((double)x / RES_WIDTH) * fl->x_width;
	fl->y_min = fl->y_offset - ((double)y / RES_HIGHT) * fl->y_width;
	printf("zoom :%f", fl->zoom);
	printf(" || iterations ration :%f\n", fl->iterations_ratio);
}

int	render_zoom(t_frctl *fl, int quadratic)
{
	render_fractal(fl, quadratic);
	fl->zoom_to_update = 0;
	return (0);
}

int	handle_mouse(int mouse_move, int x, int y, t_frctl *fl)
{
	if (mouse_move == 4)
		zoom_and_recenter(x, y, fl, '+');
	else if (mouse_move == 5)
		zoom_and_recenter(x, y, fl, '-');
	else
		return (-1);
	//	if (fl->zoom_to_update == 10)
	//		return (render_zoom(fl, 1));
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
