/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:20:32 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 21:54:49 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

uint32_t	get_color(int n)
{
	uint32_t	color;

	if (n == MAX_ITER)
		color = BLACK;
	else if (n > MAX_ITER * 0.75)
		color = RED;
	else if (n > MAX_ITER * 0.5)
		color = GREEN;
	else if (n > MAX_ITER * 0.25)
		color = BLUE;
	else
		color = WHITE;
	return (color);
}
