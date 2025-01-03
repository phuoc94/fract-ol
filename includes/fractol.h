/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/03 12:43:18 by phuocngu         ###   ########.fr       */
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
	double		julia_real;
	double		julia_imag;
}				t_data;

int				validate_args(int argc, char **argv);
void			initialize_data(t_data *data, char **argv);
int				setup_window(t_data *data, char *title);

void			draw_mandelbrot(t_data *data);
void			draw_julia(t_data *data);

uint32_t		get_color(int n);
void			zoom_func(double xdelta, double ydelta, void *param);

int				ft_strcmp(const char *s1, const char *s2);
void			ft_putstr_fd(const char *s, int fd);
double			ft_atof(const char *str);

#endif
