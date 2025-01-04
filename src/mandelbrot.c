/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:47:56 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 14:14:54 by phuocngu         ###   ########.fr       */
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

void	draw_mandelbrot(t_data *data)
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
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
	}
}
