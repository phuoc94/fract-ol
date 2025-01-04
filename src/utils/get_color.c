/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:20:32 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 18:23:58 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

uint32_t	get_color(int n)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = ((n * 5) % 256) * 256 * 256;
	g = ((n * 7) % 256) * 256;
	b = ((n * 9) % 256);
	return (r + g + b);
}

void	allocate_colors(t_data *data)
{
	int	i;

	i = 0;
	data->colors = malloc(sizeof(uint32_t *) * HEIGHT);
	while (i < HEIGHT)
	{
		data->colors[i] = malloc(sizeof(uint32_t) * WIDTH);
		i++;
	}
	data->colors[0][0] = 0;
}

void	free_colors(t_data *data)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(data->colors[i]);
		i++;
	}
	free(data->colors);
}
