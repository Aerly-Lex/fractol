/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:44:21 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/20 11:13:54 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Cleans and exits the program as failure.
void	ft_error(t_env *env)
{
	if (env->buffer)
		mlx_delete_image(env->mlx, env->buffer);
	if (env->img)
		mlx_delete_image(env->mlx, env->img);
	if (env->mlx)
		mlx_terminate(env->mlx);
	exit(EXIT_FAILURE);
}

void	render_fractal(void *window)
{
	t_env	*env;

	env = (t_env *)window;
	if (1 == env->fract_choice)
		ft_mandelbrot(env, env->img);
	else if (2 == env->fract_choice)
		ft_julia(env, env->img);
	else if (3 == env->fract_choice)
		ft_burning_ship(env, env->img);
}

int	main(int argc, char **argv)
{
	t_env	env;

	process_args(argc, argv, &env);
	data_init(&env);
	if (!mlx_loop_hook(env.mlx, render_fractal, (void *)&env))
		ft_error(&env);
	if (mlx_image_to_window(env.mlx, env.img, 0, 0) < 0)
		ft_error(&env);
	ft_hooks(&env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return (0);
}

/*
** +----------------------------+-------------------------------------------+
** |       Julia Set c Value	|           Short Description              |
** +----------------------------+-------------------------------------------+
** |	-0.7	+0.27015		| Dragon-like design						|
** |	0.355	+0.355			| Spiral design								|
** |	-0.54	+0.54			| complex symetric structur					|
** |	-0.70176	-0.3842		| Electrified cloud appearance				|
** |	0.28	-0.008			| Combination of lines and structures		|
** |	-0.8	+0.156			| spiral with small details					|
** |	0.4		0.6				| geometric islands							|
** +----------------------------+-------------------------------------------+
*/

// UNDER CONSTRUCTION
// its supposed to create the image before printing onto window...
// but there is a error when a hook is initialized

// void	render_fractal(void *window)
// {
// 	t_env	*env;

// 	env = (t_env *)window;
// 	env->buffer = mlx_new_image(env->mlx, env->height, env->width);
// 	if (!env->buffer)
// 		ft_error(env);
// 	if (1 == env->fract_choice)
// 		ft_mandelbrot(env, env->buffer);
// 	else if (2 == env->fract_choice)
// 		ft_julia(env, env->img);
// 	else if (3 == env->fract_choice)
// 		ft_burning_ship(env, env->buffer);
// 	if (mlx_image_to_window(env->mlx, env->buffer, 0, 0) < 0)
// 		ft_error(env);
// 	if (env->img)
// 		mlx_delete_image(env->mlx, env->img);
// 	env->img = env->buffer;
// 	env->buffer = NULL;
// }
