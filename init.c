/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:32:13 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/22 12:25:46 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_y_px_to_math(t_frctl *fl)
{
	return (fl->x_width * RES_HIGHT / RES_WIDTH);
}

int	init_all(t_frctl *fl)
{
	fl->mlx = mlx_init();
	if (!fl->mlx)
		p_err("Err: Failed to initiate MLX", fl);
	fl->mlx_win = mlx_new_window(fl->mlx, 1920, 1080, "Fract_ol");
	if (!fl->mlx_win)
		p_err("Err: Failed to create window", fl);
	fl->img.img = mlx_new_image(fl->mlx, RES_WIDTH, RES_HIGHT);
	if (!fl->img.img)
		p_err("Err: Failed to create image", fl);
	fl->img.addr = mlx_get_data_addr(fl->img.img, &fl->img.bpp,
			&fl->img.line_len, &fl->img.endian);
	fl->x_min = -2.5;
	fl->x_width = 4.0;
	fl->y_min = -2.0;
	fl->y_width = scale_y_px_to_math(fl);
	fl->zoom = 1.0;
	mlx_hook(fl->mlx_win, KeyPress, KeyPressMask, handle_keys, fl);
	mlx_hook(fl->mlx_win, DestroyNotify, StructureNotifyMask, close_all, fl);
	return (0);
}
