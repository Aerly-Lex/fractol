/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:53:03 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/19 16:54:55 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgba(t_env *env)
{
	double	brightness;
	int		r;
	int		g;
	int		b;

	r = (env->color & 0xFF000000) >> 24;
	g = (env->color & 0x00FF0000) >> 16;
	b = (env->color & 0x0000FF00) >> 8;
	brightness = env->iterations * 7;
	if (255 < env->iterations * 7)
		brightness = 255;
	r = (r * brightness) / 255;
	g = (g * brightness) / 255;
	b = (b * brightness) / 255;
	return (r << 24 | g << 18 | b << 8 | 0x000000FF);
}

// UNDER CONSTRUCTION //
// void	get_brightness(t_env *env, int i)
// {
	// double	brightness;
	// int		r;
	// int		g;
	// int		b;

//     r = (env->color & 0xFF000000) >> 24;
//     g = (env->color & 0x00FF0000) >> 16;
//     b = (env->color & 0x0000FF00) >> 8;
// 	if (1 == i)
// 	{
// 		env->inner_color = increase brightness
// 	}
// 	else
// 		env->inner_color = reduce brightness
// }
