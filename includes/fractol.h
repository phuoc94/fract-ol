/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 20:58:48 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <MLX42/MLX42.h>
# include <stdbool.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

typedef struct
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	double		zoom;
	double		offset_x;
	double		offset_y;
}				t_data;

uint32_t		get_color(int n);
void			draw_mandelbrot(t_data *data);
void			zoom_func(double xdelta, double ydelta, void *param);

#endif
