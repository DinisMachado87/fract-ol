/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:57:20 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/30 18:05:44 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(int keycode, t_frctl *fl)
{
	(void)keycode;
	return (close_all(fl));
}

int	close_all(t_frctl *fl)
{
	if (fl->img.img)
	{
		mlx_destroy_image(fl->mlx, fl->img.img);
		fl->img.img = NULL;
	}
	if (fl->mlx_win)
	{
		mlx_destroy_window(fl->mlx, fl->mlx_win);
		fl->mlx_win = NULL;
	}
	if (fl->mlx)
	{
		mlx_destroy_display(fl->mlx);
		free(fl->mlx);
		fl->mlx = NULL;
	}
	exit(0);
}

int	p_err(char *err, t_frctl *fl)
{
	while (*err)
		write(2, err++, 1);
	write(2, "\n", 1);
	close_all(fl);
	return (2);
}
