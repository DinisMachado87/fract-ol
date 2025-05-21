/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:32:13 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/21 14:39:06 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	fl->img.addr = mlx_get_data_addr(fl->img.img, &fl->img.bits_per_pixel,
			&fl->img.line_length, &fl->img.endian);
	mlx_hook(fl->mlx_win, KeyPress, KeyPressMask, handle_keys, fl);
	mlx_hook(fl->mlx_win, DestroyNotify, StructureNotifyMask, close_all, fl);
	return (0);
}
