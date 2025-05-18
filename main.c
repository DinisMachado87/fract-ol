/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:01:23 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/18 20:01:31 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int p_err(char *err, t_frctl *fl)
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
		fl->mlx = NULL;
	}
	while (*err)
		write(2, err++, 1);
	write(2, "\n", 1);
	return (-1);
}

int init_all(t_frctl *fl)
{
	fl->mlx = mlx_init();
	if (!fl->mlx)
		return (p_err("Err: Failed to initiate MLX", fl));
	fl->mlx_win = mlx_new_window(fl->mlx, 1920, 1080, "Fract_ol");
	if (!fl->mlx_win)
		return (p_err("Err: Failed to create window", fl));
	fl->img.img = mlx_new_image(fl->mlx, 1920, 1080);
	if (!fl->img.img)
		return (p_err("Err: Failed to create image", fl));
	fl->img.addr = mlx_get_data_addr(fl->img.img, &fl->img.bits_per_pixel,
	&fl->img.line_length, &fl->img.endian);
	return (0);
}

int main(int argc, char **argv)
{
	t_frctl fl;

	ft_memset(&fl, 0, sizeof(t_frctl));
	if ((argc == 2) && (ft_strncmp(argv[1], "Mandelbrot", 20) != 0))
	{
		if (init_all(&fl))
			return (p_err("EXITING", &fl));
	}
	else
		return (p_err(
				"Error: Available fractal case at the moment: Mandelbrot\n"
				"Please call the executable"
				"followed by your chosen fractal after a space\n", &fl));
	mlx_loop(fl.mlx);
	return (0);
}
