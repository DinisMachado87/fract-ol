/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:01:23 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/28 22:44:29 by dimachad         ###   ########.fr       */
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

int	p_err(char *err, t_frctl *fl)
{
	while (*err)
		write(2, err++, 1);
	write(2, "\n", 1);
	close_all(fl);
	return (2);
}

void	is_julia_or_mandel(int argc, char **argv, t_frctl *fl)
{
	if (ft_strncmp(argv[1], "Julia", 6) && ft_strncmp(argv[1], "Mandelbrot",
			11))
		exit(p_err("Err: Available fractals: Mandelbrot or Julia\n", fl));
	else if (!ft_strncmp(argv[1], "Mandelbrot", 10))
	{
		fl->fractal = MANDELBROT;
		fl->c.r_x = 0.0;
		fl->c.i_y = 0.0;
	}
	else if (!ft_strncmp(argv[1], "Julia", 5))
	{
		if (argc == 4 && str_to_float(argv[2]) != 0
			&& str_to_float(argv[3]) != 0)
		{
			fl->c.r_x = str_to_float(argv[2]);
			fl->c.i_y = str_to_float(argv[3]);
			fl->fractal = JULIA;
		}
		else
			exit(p_err("Err: Julia set takes two decilmal arguments\n", fl));
	}
	else
		exit(p_err("Error: Available fractal: Mandelbrot\n"
					"Please call the exe followed by your chosen fractal\n",
					fl));
}

int	main(int argc, char **argv)
{
	t_frctl	fl;

	ft_memset(&fl, 0, sizeof(t_frctl));
	if (argc >= 2)
	{
		is_julia_or_mandel(argc, argv, &fl);
		fl.x_offset = 0.0;
		fl.y_offset = 0.0;
		fl.zoom = 1.0;
		fl.zoom_to_update = 0;
		fl.iter_ratio = 1;
		init_mlx_structure(&fl);
		init_scale_image(&fl);
		init_events(&fl);
	}
	render_fractal(&fl, 0);
	mlx_loop(fl.mlx);
	return (0);
}
