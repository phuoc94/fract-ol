/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:31:41 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 20:58:27 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	zoom_func(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta < 0)
		data->zoom *= 0.9;
	else if (ydelta > 0)
		data->zoom /= 0.9;
	draw_mandelbrot(data);
}
