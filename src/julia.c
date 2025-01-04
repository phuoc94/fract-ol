/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:47:56 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 22:54:39 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calc_julia(t_complex z, t_complex c)
{
	double	temp;
	int		n;

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

static void	draw_julia_first(t_data *data, t_complex c)
{
	t_complex	z;
	int			x;
	int			y;
	int			n;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z = calc_complex(data, x, y);
			n = calc_julia(z, c);
			data->colors[y][x] = get_color(n);
			mlx_put_pixel(data->image, x, y, data->colors[y][x]);
			y++;
		}
		x++;
	}
}

void	draw_julia(t_data *data, t_complex c)
{
	if ((data->colors[0][0]) != 1)
		draw_zoom(data);
	else
		draw_julia_first(data, c);
}
