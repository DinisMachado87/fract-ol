/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:32:13 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/22 19:05:25 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	fl->x_width = 5.0 * fl->zoom;
	fl->x_min = (fl->x_width / 2 * -1) + fl->x_offset;
	fl->y_width = scale_y_px_to_math(fl);
	fl->y_min = (fl->y_width / 2 * -1) + fl->y_offset;
	return (0);
}

int	init_events(t_frctl *fl)
{
	mlx_mouse_hook(fl->mlx_win, handle_mouse, fl);
	mlx_hook(fl->mlx_win, KeyPress, KeyPressMask, handle_keys, fl);
	mlx_hook(fl->mlx_win, DestroyNotify, StructureNotifyMask, close_all, fl);
	mlx_loop_hook(fl->mlx, render_zoom, fl);
	return (0);
}
