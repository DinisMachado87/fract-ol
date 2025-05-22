/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:38:39 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/22 12:20:05 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define RES_WIDTH 1920
# define RES_HIGHT 1080
# define MAX_ITERATIONS 200
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
	double	y_min;
	double	y_width;
	double	zoom;

}			t_frctl;

int			init_all(t_frctl *fl);
int			handle_keys(int keycode, t_frctl *fl);
int			close_window(int keycode, t_frctl *fl);
int			close_all(t_frctl *fl);
void		p_err(char *err, t_frctl *fl);
void		render_fractal(t_frctl *fl);

#endif
