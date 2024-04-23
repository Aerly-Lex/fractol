/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:33:31 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/19 17:00:03 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	handle_pixel(int x, int y, t_env *env)
{
	t_complex	z;
	t_complex	c;

	env->iterations = 0;
	c.x = env->julia.x;
	c.y = env->julia.y;
	z.x = ft_map(x, 0, WIDTH, env->x) + env->shift_x;
	z.y = ft_map(y, 0, HEIGHT, env->y) + env->shift_y;
	while (env->iterations < ITERATIONS)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > env->escape_value)
		{
			mlx_put_pixel(env->img, x, y, get_rgba(env));
			return ;
		}
		env->iterations++;
	}
	mlx_put_pixel(env->img, x, y, BLACK);
}

/*
	JULIA
	./fractol julia <real> <i>
	z = pixel_point + constat
	z^2 + c
*/
void	ft_julia(t_env *env, mlx_image_t *img)
{
	t_img	pixel;

	pixel.y = -1;
	while (++pixel.y < img->height)
	{
		pixel.x = -1;
		while (++pixel.x < img->width)
		{
			handle_pixel(pixel.x, pixel.y, env);
		}
	}
}
