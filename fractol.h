/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:23:45 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/19 18:42:39 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"

//				COLORS				//
# define BLACK       0x000000FF  // RGB(0, 0, 0)
# define WHITE       0xFFFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000FF  // RGB(255, 0, 0)
# define GREEN       0x00FF00FF  // RGB(0, 255, 0)
# define BLUE        0x0000FFFF  // RGB(0, 0, 255)
# define YELLOW      0xFFFF00FF  // RGB(255, 255, 0)
# define CYAN        0x00FFFFFF  // RGB(0, 255, 255)
# define PURPLE      0x800080FF  // RGB(128, 0, 128)
# define ORANGE      0xFFA500FF  // RGB(255, 165, 0)
# define BROWN       0xA52A2AFF  // RGB(165, 42, 42)
# define PINK        0xFFC0CBFF  // RGB(255, 192, 203)
# define LIME_GREEN  0x32CD32FF  // RGB(50, 205, 50)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FFFF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00FF  // A blinding lime
# define NEON_ORANGE     0xFF6600FF  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066FF  // A deep purple
# define AQUA_DREAM      0x33CCCCFF  // A bright turquoise
# define HOT_PINK        0xFF66B2FF  // As the name suggests!
# define LAVA_RED        0xFF3300FF  // A bright, molten red

# define WIDTH 1500
# define HEIGHT 1500
# define ITERATIONS 100
# define HELP "Invalid Input\n\
Please enter additional parameter:\
\n-1 (Mandelbrot)\
\n-2 (Julia) -number - number (Float from -2 to 2.0)\
\n-3 Burning Ship\n"

// x = real
// y = imag
typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

typedef struct s_img {
	uint32_t	x;
	uint32_t	y;
	double		x_map;
	double		y_map;
}	t_img;

typedef struct s_map {
	double	min;
	double	max;
}	t_map;

typedef struct s_julia {
	double	x;
	double	y;
}	t_julia;

typedef struct s_environment {
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*buffer;
	int			img_or_buf;
	int32_t		width;
	int32_t		height;
	int			iterations;
	int			fract_choice;
	double		escape_value;
	t_map		x;
	t_map		y;
	double		zoom;
	t_julia		julia;
	double		shift_x;
	double		shift_y;
	int			color;
}	t_env;

//				MAIN					//
int				main(int argc, char **argv);
void			ft_error(t_env *env);

//				INITIALIZATION			//
void			data_init(t_env *window);
void			ft_hooks(t_env *env);
void			ft_key(mlx_key_data_t keydata, void *param);
void			process_args(int argc, char **argv, t_env *env);
int				get_rgba(t_env *env);
void			render_fractal(void *window);

//				MATHS					//
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
double			ft_map(double orig, double old_min, \
				double old_max, t_map map);

//				FRACTALS				//
void			ft_mandelbrot(t_env *env, mlx_image_t *img);
void			ft_julia(t_env *env, mlx_image_t *img);
void			ft_burning_ship(t_env *env, mlx_image_t *img);

//				STRING-UTILS			//
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atod(char *s);

#endif
