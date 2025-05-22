/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:04 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/22 15:45:20 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int mouse_move, int x, int y, t_frctl *fl)
{
	printf("%d", mouse_move);
	(void)y;
	(void)x;
	if (mouse_move == 4)
		fl->zoom *= 1.05;
	else if (mouse_move == 5)
		fl->zoom *= 0.95;
	else
		return (-1);
	init_scale_image(fl);
	render_fractal(fl);
	return (0);
}

int	handle_keys(int keycode, t_frctl *fl)
{
	printf("%d", keycode);
	if (keycode == 65307)
		return (close_all(fl));
	return (-1);
}

int	close_window(int keycode, t_frctl *fl)
{
	(void)keycode;
	return (close_all(fl));
}
