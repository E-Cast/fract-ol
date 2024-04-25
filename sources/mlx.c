/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:40:31 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/25 16:44:47 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "float.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (ydelta != 0)
	{
		fract->zoom += ydelta / ZOOM_STRENGTH;
		mlx_get_mouse_pos(fract->mlx, &fract->mx, &fract->my);
	}
	printf("%f\nx:%i/y:%i\n", ((t_fractol *)param)->zoom, fract->mx, fract->my);//
	(void) xdelta;
}

void	hook(void *param)
{
	t_fractol	*frct;
	mlx_t		*mlx;

	frct = (t_fractol *)param;
	mlx = frct->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (frct->zoom != frct->zoom_last)
	{
		frct->zoom_last = frct->zoom;
		// printf("render time!\n");
		render(frct);
		if (mlx_image_to_window(mlx, frct->image, 0, 0) < 0)
		{
			ft_putendl_fd("Error: failed to display image to window",
				STDERR_FILENO);
			mlx_close_window(mlx);
		}
	}
}

int	mlx_start(mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "fractol", 0);
	if (!*mlx)
		return (EXIT_FAILURE);
	*image = mlx_new_image(*mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!*image)
		return (mlx_terminate(*mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
