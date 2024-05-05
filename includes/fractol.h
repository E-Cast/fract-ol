/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:20:15 by ecastong          #+#    #+#             */
/*   Updated: 2024/05/05 10:24:13 by ecastong         ###   ########.fr       */
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

# ifndef ESC_RAD
#  define ESC_RAD 2.0
# endif

# ifndef PALETTE
#  define PALETTE 0xFCBE11FF
# endif

# ifndef SENSITIVITY
#  define SENSITIVITY 0.5
# endif

typedef enum e_fractals_enum
{
	JULIA,
	MANDEL
}	t_fract_e;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fract_e	fractal;
	double		julia_cx;
	double		julia_cy;
	bool		update;
	double		zoom;
	double		offset_x;
	double		offset_y;
}	t_fractol;

/*main.c*/

int		read_input(int argc, char **argv, t_fractol *fract);

/*mlx.c*/

void	scrollhook(double xdelta, double ydelta, void *param);
void	update_offset(t_fractol	*f);
void	hook(void *param);
int		mlx_start(mlx_t **mlx, mlx_image_t **image);

/*render.c*/

int		iter_mandel(t_fractol *f, double zx, double zy);
int		iter_julia(t_fractol *f, int px, int py);
void	render(t_fractol *fract);

#endif