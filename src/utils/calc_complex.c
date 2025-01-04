/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:43:48 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/04 23:03:23 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_complex	calc_complex(t_data *data, int x, int y)
{
	t_complex	z;

	z.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom;
	z.imag = -(y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom;
	return (z);
}
