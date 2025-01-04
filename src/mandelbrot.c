/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:47:56 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 18:19:40 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calc_mandelbrot(t_complex c)
{
	t_complex	z;
	double		temp;
	int			n;

	z.real = 0;
	z.imag = 0;
	n = 0;
	while (is_within_radius(z) && n < MAX_ITER)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		n++;
	}
	return (n);
}

static void	draw_mandelbrot_first(t_data *data)
{
	t_complex	c;
	int			x;
	int			y;
	int			n;
	int			color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom;
			c.imag = -(y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom;
			n = calc_mandelbrot(c);
			color = get_color(n);
			data->colors[y][x] = color;
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_mandelbrot(t_data *data)
{
	if ((data->colors[0][0]) != 0)
		draw_zoom(data);
	else
		draw_mandelbrot_first(data);
}
