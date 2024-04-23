/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:22:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/20 10:51:08 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_color(t_env *env)
{
	if (mlx_is_key_down(env->mlx, MLX_KEY_1))
		env->color = BROWN;
	if (mlx_is_key_down(env->mlx, MLX_KEY_2))
		env->color = BLUE;
	if (mlx_is_key_down(env->mlx, MLX_KEY_3))
		env->color = RED;
	if (mlx_is_key_down(env->mlx, MLX_KEY_4))
		env->color = MAGENTA_BURST;
	if (mlx_is_key_down(env->mlx, MLX_KEY_5))
		env->color = PSYCHEDELIC_PURPLE;
	if (mlx_is_key_down(env->mlx, MLX_KEY_6))
		env->color = AQUA_DREAM;
	if (mlx_is_key_down(env->mlx, MLX_KEY_7))
		env->color = HOT_PINK;
	if (mlx_is_key_down(env->mlx, MLX_KEY_8))
		env->color = CYAN;
	if (mlx_is_key_down(env->mlx, MLX_KEY_9))
		env->color = LAVA_RED;
	render_fractal(&env);
}

void	ft_key(mlx_key_data_t keydata, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	(void)keydata;
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		env->shift_x += 0.25 * (env->x.min * 0.4);
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		env->shift_x -= 0.25 * (env->x.min * 0.4);
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
		env->shift_y -= 0.25 * (env->x.min * 0.4);
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP))
		env->shift_y += 0.25 * (env->x.min * 0.4);
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	ft_key_color(env);
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (ydelta > 0 || xdelta > 0)
	{
		env->x.min *= 0.90;
		env->x.max *= 0.90;
		env->y.min *= 0.90;
		env->y.max *= 0.90;
	}
	else if (ydelta < 0 || xdelta < 0)
	{
		env->x.min *= 1.10;
		env->x.max *= 1.10;
		env->y.min *= 1.10;
		env->y.max *= 1.10;
	}
	render_fractal(&env);
}

void	ft_resize(int32_t width, int32_t height, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	env->buffer = mlx_new_image(env->mlx, width, height);
	if (!env->buffer)
		ft_error(env);
	env->height = height;
	env->width = width;
	if (mlx_image_to_window(env->mlx, env->buffer, 0, 0) < 0)
		ft_error(env);
	render_fractal(&env);
	mlx_delete_image(env->mlx, env->img);
	env->img = env->buffer;
	env->buffer = NULL;
}

void	ft_hooks(t_env *env)
{
	mlx_key_hook(env->mlx, ft_key, env);
	mlx_scroll_hook(env->mlx, ft_scroll, env);
	mlx_resize_hook(env->mlx, ft_resize, env);
}

// UNDER CONSTRUCTION
// void	ft_cursor(mlx_t* mlx, mlx_cursorfunc func, void* param)
// {
// 	t_env	*env;

// 	env = (t_env *)param;
// }

// void mlx_cursor_hook(mlx_t* mlx, mlx_mousefunc func, void* param);
// void	mouse_position_handler(double xpos, double ypos, void *param);
// mlx_cursor_hook(env->mlx, ft_cursor, env);
