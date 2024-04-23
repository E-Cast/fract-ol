/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/23 00:45:32 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol	fract)
{
	int	sx;
	int	sy;

	sx = 0;
	while (sx < WIN_WIDTH)
	{
		sy = 0;
		while (sy < WIN_HEIGHT)
		{
			sy++;
		}
		sx++;
	}
}

int	main(void)
{
	t_fractol	fract;

	if (mlx_start(&fract.mlx, &fract.image) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop_hook(fract.mlx, &keyhook, &fract);
	mlx_scroll_hook(fract.mlx, &scrollhook, NULL);
	mlx_loop(fract.mlx);
	//calculate pixel using formula function
	//calculate every pixel function
	//move functions
	//clear function
	mlx_delete_image(fract.mlx, fract.image);
	mlx_terminate(fract.mlx);
}
