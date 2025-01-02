/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:11:42 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 17:58:22 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true)))
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	draw_mandelbrot(image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
