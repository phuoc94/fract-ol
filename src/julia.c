/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:47:56 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/03 20:14:23 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calc_julia(t_complex z, t_complex c)
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

void	draw_julia(t_data *data, t_complex	c)
{
	t_complex	z;
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
			z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom
				+ data->offset_x;
			z.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom
				+ data->offset_y;
			n = calc_julia(z, c);
			color = get_color(n);
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
	}
}
