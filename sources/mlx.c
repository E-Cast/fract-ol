/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:40:31 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/24 16:54:11 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	if (ydelta > 0)
		puts("in");//
	else if (ydelta < 0)
		puts("out");//
	(void) xdelta;
	(void) param;
}

void	hook(void *param)
{
	t_fractol	*frct;
	mlx_t		*mlx;

	frct = (t_fractol *)param;
	mlx = frct->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		puts("left");//
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		puts("up");//
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		puts("down");//
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		puts("right");//
	render(frct);
	if (mlx_image_to_window(mlx, frct->image, 0, 0) < 0)
	{
		ft_putendl_fd("Error: failed to display image to window",
			STDERR_FILENO);
		mlx_close_window(mlx);
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
