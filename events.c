/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:04 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/20 16:27:07 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keys(int keycode, t_frctl *fl)
{
	if (keycode == 65307)
		return (close_all(fl));
	(void)fl;
	return (-1);
}

int	close_window(int keycode, t_frctl *fl)
{
	(void)keycode;
	return (close_all(fl));
}
