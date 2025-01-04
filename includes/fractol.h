/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 22:44:53 by phuocngu         ###   ########.fr       */
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

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_data
{
	char		*title;
	mlx_t		*mlx;
	mlx_image_t	*image;
	double		zoom;
	double		julia_real;
	double		julia_imag;
	uint32_t	**colors;
}				t_data;

int				validate_args(int argc, char **argv);
void			initialize_data(t_data *data, char **argv);
int				setup_window(t_data *data);

void			draw_mandelbrot(t_data *data);
void			draw_julia(t_data *data, t_complex c);

uint32_t		get_color(int n);
void			allocate_colors(t_data *data);
void			zoom_func(double xdelta, double ydelta, void *param);
void			draw_zoom(t_data *data);
void			esc_key_func(mlx_key_data_t keydata, void *param);
int				is_within_radius(t_complex z);
void			free_colors(t_data *data);
int				calc_mandelbrot(t_complex c);
int				calc_julia(t_complex z, t_complex c);
t_complex		calc_complex(t_data *data, int x, int y);

int				ft_strcmp(const char *s1, const char *s2);
void			ft_putstr_fd(const char *s, int fd);
double			ft_atof(const char *str);

#endif
