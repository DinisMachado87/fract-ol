/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:04 by dimachad          #+#    #+#             */
/*   Updated: 2025/05/26 17:20:48 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int update_scale_image(t_frctl *fl) {
  fl->x_width = 5.0 * fl->zoom;
  fl->y_width = scale_y_px_to_math(fl);
  if (fl->x_min < 0.0) {
    fl->x_min = (fl->x_min + (fl->x_width / 2 / 2 * fl->x_offset)) / 2;
    fl->y_min = (fl->y_min + (fl->y_width / 2 / 2 * fl->y_offset)) / 2;
  } else {
    fl->x_min = (fl->x_min + (fl->x_width / 2 / 2 * -fl->x_offset)) / 2;
    fl->y_min = (fl->y_min + (fl->y_width / 2 / 2 * -fl->y_offset)) / 2;
  }
  printf("x_min %f, y_min %f || ", fl->x_min, fl->y_min);
  printf("x_off %f, y_off %f || ", fl->x_offset, fl->y_offset);
  printf("zoom %f\n", fl->zoom);
  return (0);
}

// update zoom and calculate offset % center zoom by mouse position
static void zoom_and_recenter(int x, int y, t_frctl *fl, char zoom) {
  x = x - (RES_WIDTH / 2);
  y = y - (RES_HIGHT / 2);
  if (zoom == '-') {
    fl->zoom *= 0.95;
    x *= -1;
    y *= -1;
  } else
    fl->zoom *= 1.05;
  fl->x_offset = (fl->x_offset + (float)x / (float)RES_WIDTH) / 2;
  fl->y_offset = (fl->y_offset + (float)y / (float)RES_HIGHT) / 2;
  printf("x_off %f, y_off %f \n", fl->x_offset, fl->y_offset);
}

int render_zoom(t_frctl *fl, int quadratic) {
  update_scale_image(fl);
  render_fractal(fl, quadratic);
  fl->zoom_to_update = 0;
  return (0);
}

int handle_mouse(int mouse_move, int x, int y, t_frctl *fl) {
  if (mouse_move == 5)
    zoom_and_recenter(x, y, fl, '-');
  else if (mouse_move == 4)
    zoom_and_recenter(x, y, fl, '+');
  else
    return (-1);
  if (fl->zoom_to_update == 10)
    return (render_zoom(fl, 1));
  else
    fl->zoom_to_update++;
  return (0);
}

int handle_keys(int keycode, t_frctl *fl) {
  if (keycode == 65307)
    return (close_all(fl));
  else if (keycode == 65361)
    fl->x_offset -= fl->x_width / 5;
  else if (keycode == 65363)
    fl->x_offset += fl->x_width / 5;
  else if (keycode == 65362)
    fl->y_offset -= fl->y_width / 5;
  else if (keycode == 65364)
    fl->y_offset += fl->y_width / 5;
  init_scale_image(fl);
  render_fractal(fl, 1);
  return (-1);
}

int close_window(int keycode, t_frctl *fl) {
  (void)keycode;
  return (close_all(fl));
}
