/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:01:24 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/20 10:55:35 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	handle_pixel(int x, int y, t_env *env, mlx_image_t *img)
{
	t_complex	z;
	t_complex	c;

	(void)img;
	env->iterations = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(x, 0, WIDTH, env->x) + env->shift_x;
	c.y = ft_map(y, 0, HEIGHT, env->y) + env->shift_y;
	while (env->iterations < ITERATIONS)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > env->escape_value)
		{
			mlx_put_pixel(img, x, y, get_rgba(env));
			return ;
		}
		env->iterations++;
	}
	mlx_put_pixel(img, x, y, BLACK);
}

/*
	MANDELBROT
	z = z^2 + c
	z initally is (0, 0)
	c is the actual point
*/
void	ft_mandelbrot(t_env *env, mlx_image_t *img)
{
	t_img	pixel;

	pixel.y = -1;
	while (++pixel.y < img->height)
	{
		pixel.x = -1;
		while (++pixel.x < img->width)
		{
			handle_pixel(pixel.x, pixel.y, env, img);
		}
	}
}
