/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:56:11 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/19 15:56:43 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Vector Additon
// z^2 + c
// z = z^2 + c
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

// Square
// real = (x^2 - y^2)
// imag = 2 * x * y
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

/**
	@brief Scales the map to a certain range

	@param orig The original Value
	@param old_min The original mininum map
	@param old_max The original maximum map
	@param map the new_min and new_max value
	@return the new value
*/
double	ft_map(double orig, double old_min, double old_max, t_map map)
{
	return ((orig - old_min) * (map.max - map.min) \
			/ (old_max - old_min) + map.min);
}
