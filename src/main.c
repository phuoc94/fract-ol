/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:11:42 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/03 17:19:47 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_fractal(t_data *data, char *fractal_type)
{
	if (ft_strcmp(fractal_type, "mandelbrot") == 0)
		draw_mandelbrot(data);
	else if (ft_strcmp(fractal_type, "julia") == 0)
		draw_julia(data);
}

int32_t	main(int argc, char **argv)
{
	t_data	data;

	if (validate_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	initialize_data(&data, argv);
	if (setup_window(&data, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	draw_fractal(&data, argv[1]);
	mlx_scroll_hook(data.mlx, zoom_func, &data);
	mlx_key_hook(data.mlx, &esc_key_func, NULL);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
