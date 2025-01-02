/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:11:42 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 20:58:36 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int32_t	main(void)
{
	t_data	data;

	data.zoom = 1.0;
	data.offset_x = 0.0;
	data.offset_y = 0.0;
	if (!(data.mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true)))
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(data.mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	draw_mandelbrot(&data);
	mlx_scroll_hook(data.mlx, zoom_func, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
