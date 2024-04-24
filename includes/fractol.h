/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:20:15 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/24 16:08:12 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <math.h>
# include <MLX42/MLX42.h>
# include "libft.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1280
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 720
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 500
# endif


typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_ivec2
{
	int	x;
	int	y;
}	t_ivec2;

typedef enum e_fractals
{
	MANDEL,
	JULIA,
	SHIP,
	NEWTON,
	ERROR
}	t_fractals;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			x;
	int			y;
	t_fractals	fractal;
}	t_fractol;

void	keyhook(void *param);
void	scrollhook(double xdelta, double ydelta, void *param);
int		mlx_start(mlx_t **mlx, mlx_image_t **image);

#endif