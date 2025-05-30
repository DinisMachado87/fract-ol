/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:32:13 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/30 18:06:56 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>

double	scale_y_px_to_math(t_frctl *fl)
{
	return (fl->x_width * (double)RES_HIGHT / (double)RES_WIDTH);
}

int	init_mlx_structure(t_frctl *fl)
{
	fl->mlx = mlx_init();
	if (!fl->mlx)
		p_err("Err: Failed to initiate MLX", fl);
	fl->mlx_win = mlx_new_window(fl->mlx, RES_WIDTH, RES_HIGHT, "Fract_ol");
	if (!fl->mlx_win)
		p_err("Err: Failed to create window", fl);
	fl->img.img = mlx_new_image(fl->mlx, RES_WIDTH, RES_HIGHT);
	if (!fl->img.img)
		p_err("Err: Failed to create image", fl);
	fl->img.addr = mlx_get_data_addr(fl->img.img, &fl->img.bpp,
			&fl->img.line_len, &fl->img.endian);
	return (0);
}

int	init_scale_image(t_frctl *fl)
{
	fl->x_width = 4.0 * fl->zoom;
	if (fl->fractal == MANDELBROT)
		fl->x_min = (fl->x_width / 3 * -2);
	else
		fl->x_min = (fl->x_width / 2 * -1);
	fl->y_width = scale_y_px_to_math(fl);
	if (fl->fractal == MANDELBROT)
		fl->y_min = (fl->y_width / 3 * -1.5);
	else
		fl->y_min = (fl->y_width / 2 * -1);
	return (0);
}

static int	render_zoom_full(t_frctl *fl)
{
	if (fl->zoom_to_update)
	{
		render_fractal(fl, 0);
		fl->zoom_to_update = 0;
	}
	return (0);
}

int	init_events(t_frctl *fl)
{
	mlx_mouse_hook(fl->mlx_win, handle_mouse, fl);
	mlx_hook(fl->mlx_win, MotionNotify, PointerMotionMask, handle_mouse_motion,
		fl);
	mlx_hook(fl->mlx_win, KeyPress, KeyPressMask, handle_keys, fl);
	mlx_hook(fl->mlx_win, DestroyNotify, StructureNotifyMask, close_all, fl);
	mlx_loop_hook(fl->mlx, render_zoom_full, fl);
	return (0);
}
