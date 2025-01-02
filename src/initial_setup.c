/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:26:52 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 21:59:50 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	validate_args(int argc, char **argv)
{
	if (argc < 2 || (strcmp(argv[1], "mandelbrot") != 0 && strcmp(argv[1],
				"julia") != 0))
	{
		printf("Error: Invalid argument.\n");
		printf("Usage: ./fractol mandelbrot | julia [<real> <imag>]\n");
		return (EXIT_FAILURE);
	}
	if (strcmp(argv[1], "mandelbrot") == 0 && argc != 2)
	{
		printf("Error: Mandelbrot does not take additional arguments.\n");
		return (EXIT_FAILURE);
	}
	if (strcmp(argv[1], "julia") == 0 && argc != 2 && argc != 4)
	{
		printf("Error: Invalid number of arguments for Julia.\n");
		printf("Usage: ./fractol julia [<real> <imag>]\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	initialize_data(t_data *data, char **argv)
{
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	if (strcmp(argv[1], "julia") == 0 && argv[2] && argv[3])
	{
		data->julia_real = atof(argv[2]);
		data->julia_imag = atof(argv[3]);
	}
}

int	setup_window(t_data *data, char *title)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, title, true);
	if (!data->mlx)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		printf("%s", mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	return (EXIT_SUCCESS);
}
