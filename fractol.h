/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:38:39 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/27 17:09:06 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define RES_WIDTH 1300
# define RES_HIGHT 800
# define MAX_ITERATIONS 50
# define BLACK 0xFF000000

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
}			t_frctl;

// static float	str_to_decimals(char *str);
double		scale_y_px_to_math(t_frctl *fl);
double		scale_pixel(int pixel_coordinate, int axis, double range,
				double min);
int			init_mlx_structure(t_frctl *fl);
int			init_scale_image(t_frctl *fl);
int			init_events(t_frctl *fl);
int			handle_mouse(int mouse_move, int x, int y, t_frctl *fl);
int			handle_keys(int keycode, t_frctl *fl);
int			render_zoom(t_frctl *fl, int quadratic);
int			close_window(int keycode, t_frctl *fl);
int			close_all(t_frctl *fl);
void		p_err(char *err, t_frctl *fl);
void		render_fractal(t_frctl *fl, int quadratic);

#endif
