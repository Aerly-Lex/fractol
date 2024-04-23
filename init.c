/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:36:21 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/20 11:02:53 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 	mlx_set_setting(MLX_MAXIMIZED, true);
// escape->value = 2 ^ 2 - hypotenuse

// Initializes GUI, Image and inserts some Data into env
void	data_init(t_env *env)
{
	env->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->width = WIDTH;
	env->height = HEIGHT;
	env->img_or_buf = 1;
	env->escape_value = 4;
	env->x.min = -2;
	env->x.max = 2;
	env->y.min = -2;
	env->y.max = 2;
	env->zoom = 1.0;
	env->shift_x = 0.0;
	env->shift_y = 0.0;
	env->color = LIME_GREEN;
}

static void	ft_julia_checker(t_env *env)
{
	if (2 < env->julia.x || -2 > env->julia.x)
	{
		ft_printf("Please enter a number between -2 and 2\n");
		exit(EXIT_FAILURE);
	}
	else if (2 < env->julia.y || -2 > env->julia.y)
	{
		ft_printf("Please enter a number between -2 and 2\n");
		exit(EXIT_FAILURE);
	}
}

void	process_args(int argc, char **argv, t_env *env)
{
	if ((1 == argc) || 5 <= argc)
	{
		ft_printf(HELP);
		exit(EXIT_FAILURE);
	}
	else if (0 == ft_strncmp(argv[1], "-1", 3) && argc == 2)
		env->fract_choice = 1;
	else if (0 == ft_strncmp(argv[1], "-2", 3) && 4 == argc)
	{
		env->fract_choice = 2;
		env->julia.x = ft_atod(argv[2]);
		env->julia.y = ft_atod(argv[3]);
		ft_julia_checker(env);
	}
	else if (0 == ft_strncmp(argv[1], "-3", 3) && argc == 2)
		env->fract_choice = 3;
	else
	{
		ft_printf(HELP);
		exit(EXIT_FAILURE);
	}
}
