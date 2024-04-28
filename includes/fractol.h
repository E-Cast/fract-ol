/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:20:15 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 09:20:15 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <math.h>
# include <MLX42/MLX42.h>
# include "libft.h"

# ifndef WIN_SIZE
#  define WIN_SIZE 900
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 50
# endif

//less is more
# ifndef ZOOM_STRENGTH
#  define ZOOM_STRENGTH 10
# endif

# ifndef ESC_RAD
#  define ESC_RAD 2.0
# endif

# ifndef PALETTE
#  define PALETTE 0xFCBE11FF
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
	double		center[2];
	double		julia_cx;
	double		julia_cy;
}	t_fractol;

void	hook(void *param);
void	scrollhook(double xdelta, double ydelta, void *param);
int		mlx_start(mlx_t **mlx, mlx_image_t **image);

void	render(t_fractol *fract);
double	scale(int y, double a, double b);
int		iter_mandel(double zx, double zy);
void	render_mendel(t_fractol *fract);
int		iter_julia(int px, int py, double cx, double cy);
void	render_julia(t_fractol *fract, double cx, double cy);
int		iter_ship(double x, double y);
void	render_ship(t_fractol *fract);

#endif