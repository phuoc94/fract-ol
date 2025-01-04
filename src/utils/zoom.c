/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:31:41 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 23:02:25 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	zoom_func(double xdelta, double ydelta, void *param)
{
	t_data		*data;
	t_complex	c;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta < 0)
		data->zoom *= 0.9;
	else if (ydelta > 0)
		data->zoom /= 0.9;
	if (ft_strcmp(data->title, "julia") == 0)
	{
		c.real = data->julia_real;
		c.imag = data->julia_imag;
		draw_julia(data, c);
	}
	else
		draw_mandelbrot(data);
}

static uint32_t	get_pixel_color(t_data *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			cache_x;
	int			cache_y;

	cache_x = (int)((x - WIDTH / 2.0) / data->zoom + WIDTH / 2.0);
	cache_y = (int)((y - HEIGHT / 2.0) / data->zoom + HEIGHT / 2.0);
	if (cache_x >= 0 && cache_x < WIDTH && cache_y >= 0 && cache_y < HEIGHT)
		return (data->colors[cache_y][cache_x]);
	else
	{
		z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom;
		z.imag = -(y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom;
		if (ft_strcmp(data->title, "julia") == 0)
		{
			c.imag = data->julia_imag;
			c.real = data->julia_real;
			return (get_color(calc_julia(z, c)));
		}
		else
			return (get_color(calc_mandelbrot(z)));
	}
}

void	draw_zoom(t_data *data)
{
	int			x;
	int			y;
	uint32_t	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color = get_pixel_color(data, x, y);
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
	}
}
