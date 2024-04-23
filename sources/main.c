/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/23 00:09:47 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	// mlx_t	*mlx;

	// mlx = param;
	//exit the loop
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		puts("test");
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
	mlx_key_hook(mlx, &keyhook, NULL);
	mlx_scroll_hook(mlx, &scrollhook, NULL);
	mlx_loop(mlx);
	//calculate pixel using formula function
	//calculate every pixel function
	//scroll functions
	//move functions
	//clear function
}
