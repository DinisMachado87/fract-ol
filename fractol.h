/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:38:39 by dimachad          #+#    #+#             */
/*   Updated: 2025/06/02 11:51:50 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <stdio.h>

# define MOTION_NOTIFY 6
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17
# define POINTER_MOTION_MASK 64 // 1L << 6
# define KEY_PRESS_MASK 1 // 1L << 0
# define STRUCTURE_NOTIFY_MASK 131072 // 1L << 17
# define MANDELBROT 1
# define JULIA 2
# define GREEN 2
# define RED 3
# define BLUE 4
# define RES_WIDTH 1300
# define RES_HIGHT 800
# define MAX_ITERATIONS 30
# define BLACK 0xFF000000
# define THRESHOLD 0.02
# define ESC_KE 65307
# define F_KE 102
# define C_KE 99
# define A_LEFT 65361
# define A_RIGHT 65363 
# define A_UP 65362
# define A_DOWN 65364 
# define M_TITLE "Fract-ol     MANDELBROT"
# define J_TITLE "Fract-ol     JULIA SET"
# define BLUE_STR "[C]olor      BLUE"
# define GREEN_STR "[C]olor      GREEN"
# define RED_STR "[C]olor      RED"
# define TRIPPY_STR "[C]olor      TRIPPY"
# define ON_FIRE "[F]ire       ON"
# define OFF_FIRE "[F]ire       OFF"
# define ARROWS "Arrows       move"
# define WHEEL "Wheel        zoom"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_complex
{
	double	r_x;
	double	i_y;
}			t_c;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	x_min;
	double	x_width;
	double	x_offset;
	double	y_min;
	double	y_width;
	double	y_offset;
	double	zoom;
	double	iter_ratio;
	int		zoom_to_update;
	int		fractal;
	int		color;
	int		mouse_coordinates;
	t_c		c;
}			t_frctl;

float		str_to_float(const char *nptr);
double		scale_y_px_to_math(t_frctl *fl);
double		scale_pixel(int pixel_coordinate, int axis, double range,
				double min);
int			init_mlx_structure(t_frctl *fl);
int			init_scale_image(t_frctl *fl);
int			init_events(t_frctl *fl);
int			handle_mouse(int mouse_move, int x, int y, t_frctl *fl);
int			handle_mouse_motion(int x, int y, t_frctl *fl);
int			handle_keys(int keycode, t_frctl *fl);
int			close_window(int keycode, t_frctl *fl);
int			close_all(t_frctl *fl);
int			p_err(char *err, t_frctl *fl);
int			color_calc(int iterations, t_frctl *fl);
void		fractal_calc(t_c px, t_frctl *fl, int quadratic);
void		render_fractal(t_frctl *fl, int quadratic);

#endif
