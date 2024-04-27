/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:20:15 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/27 08:44:22 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <math.h>
# include <MLX42/MLX42.h>
# include "libft.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1000
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 720
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 50
# endif

//less is more
# ifndef ZOOM_STRENGTH
#  define ZOOM_STRENGTH 10
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

typedef enum e_fractals_enum
{
	MANDEL,
	JULIA,
	SHIP,
	NEWTON,
	ERROR
}	t_fract_e;

typedef struct s_fractol
{
	t_fract_e	fractal;
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			x;
	int			y;
	double		zoom;
	double		l_zoom;
	int32_t		mouse[2];
	int32_t		l_mouse[2];
}	t_fractol;

void	hook(void *param);
void	scrollhook(double xdelta, double ydelta, void *param);
int		mlx_start(mlx_t **mlx, mlx_image_t **image);


void	render(t_fractol *fract);
#endif