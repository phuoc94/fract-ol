/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_within_radius.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:11:59 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/03 18:12:46 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	is_within_radius(t_complex z)
{
	return (z.real * z.real + z.imag * z.imag <= 4);
}
