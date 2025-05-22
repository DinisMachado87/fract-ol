/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:01:23 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/22 19:39:33 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	p_err(char *err, t_frctl *fl)
{
	while (*err)
		write(2, err++, 1);
	write(2, "\n", 1);
	close_all(fl);
}

int	main(int argc, char **argv)
{
	t_frctl	fl;

	ft_memset(&fl, 0, sizeof(t_frctl));
	if ((argc == 2) && (ft_strncmp(argv[1], "Mandelbrot", 10) == 0))
	{
		fl.zoom = 1.0;
		fl.x_offset = 0.0;
		fl.x_offset = 0.0;
		fl.zoom_to_update = 0;
		init_mlx_structure(&fl);
		init_scale_image(&fl);
		init_events(&fl);
	}
	else
		p_err("Error: Available fractal at the moment: Mandelbrot\n"
				"Please call the exe followed by your chosen fractal after a space\n",
				&fl);
	render_fractal(&fl);
	mlx_loop(fl.mlx);
	return (0);
}
