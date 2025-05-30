/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:01:23 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/30 21:44:09 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_values(t_frctl *fl, float c_r_x, float c_i_y, int coordinates)
{
	fl->c.r_x = c_r_x;
	fl->c.i_y = c_i_y;
	fl->mouse_coordinates = coordinates;
}

void	is_julia_or_mandel(int argc, char **argv, t_frctl *fl)
{
	if (ft_strncmp(argv[1], "Julia", 6)
		&& ft_strncmp(argv[1], "Mandelbrot", 11))
		exit(p_err("Err: Available fractals: Mandelbrot or Julia\n", fl));
	else if (!ft_strncmp(argv[1], "Mandelbrot", 10))
	{
		fl->fractal = MANDELBROT;
		init_values(fl, 0.0, 0.0, 0);
	}
	else if (!ft_strncmp(argv[1], "Julia", 5))
	{
		if (argc == 4 && str_to_float(argv[2]) != 0
			&& str_to_float(argv[3]) != 0)
		{
			fl->fractal = JULIA;
			init_values(fl, str_to_float(argv[2]), str_to_float(argv[3]), 1);
		}
		else
			exit(p_err("Err: Julia set takes two decilmal arguments\n", fl));
	}
	else
		exit(p_err("Error: Available fractal: Mandelbrot and Julia\n"
				"Please call the exe followed by your chosen fractal\n", fl));
}

int	main(int argc, char **argv)
{
	t_frctl	fl;

	if (argc < 2)
		exit(p_err("Error: Available fractal: Mandelbrot and Julia\n"
				"Please call the exe followed by your chosen fractal\n", &fl));
	ft_memset(&fl, 0, sizeof(t_frctl));
	is_julia_or_mandel(argc, argv, &fl);
	fl.x_offset = 0.0;
	fl.y_offset = 0.0;
	fl.zoom = 1.0;
	fl.zoom_to_update = 0;
	fl.iter_ratio = 1;
	fl.color = BLUE;
	init_mlx_structure(&fl);
	init_scale_image(&fl);
	init_events(&fl);
	render_fractal(&fl, 0);
	mlx_loop(fl.mlx);
	return (0);
}
