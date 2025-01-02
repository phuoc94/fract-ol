/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:47:56 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 21:42:59 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calc_julia(t_complex c)
{
	(void)c;
	return (0);
}

void	draw_julia(t_data *data)
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
			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom
				+ data->offset_x;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom
				+ data->offset_y;
			n = calc_julia(c);
			color = get_color(n);
			mlx_put_pixel(data->image, x, y, color);
			y++;
		}
		x++;
	}
}
