/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/23 00:26:41 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		puts("left");
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		puts("up");
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		puts("down");
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		puts("right");
	(void) param;
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	(void) xdelta;
	(void) param;
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

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*image;

	//init mlx function
	if (mlx_start(&mlx, &image) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//handle inputs (escape, arrows, wasd, scroll)
	//scroll functions
	mlx_loop_hook(mlx, &keyhook, mlx);
	mlx_scroll_hook(mlx, &scrollhook, NULL);
	mlx_loop(mlx);
	//calculate pixel using formula function
	//calculate every pixel function
	//move functions
	//clear function
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
}
