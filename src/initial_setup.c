/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:26:52 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/03 13:03:18 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	validate_args(int argc, char **argv)
{
	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
				"julia") != 0))
	{
		ft_putstr_fd("Error: Invalid argument.\n", 2);
		ft_putstr_fd("Usage: ./fractol mandelbrot | julia <real> <imag>\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc != 2)
	{
		ft_putstr_fd("Error: Mandelbrot takes no arguments.\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "julia") == 0 && argc != 2 && argc != 4)
	{
		ft_putstr_fd("Error: Invalid number of arguments for Julia.\n", 2);
		ft_putstr_fd("Usage: ./fractol julia [<real>] [<imag>]\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	initialize_data(t_data *data, char **argv)
{
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	if (ft_strcmp(argv[1], "julia") == 0 && argv[2] && argv[3])
	{
		data->julia_real = ft_atof(argv[2]);
		data->julia_imag = ft_atof(argv[3]);
	}
}

int	setup_window(t_data *data, char *title)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, title, true);
	if (!data->mlx)
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return (EXIT_FAILURE);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return (EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	return (EXIT_SUCCESS);
}
