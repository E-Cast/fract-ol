/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/05/03 11:01:37 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	read_input(int argc, char **argv, t_fractol *fract)
{
	if (my_strcmp(argv[1], "julia") == 0)
	{
		fract->julia_cx = -0.8;
		fract->julia_cy = 0.156;
		if (argc >= 3)
			fract->julia_cx = my_atof(argv[2]);
		if (argc >= 4)
			fract->julia_cy = my_atof(argv[3]);
		return (JULIA);
	}
	else if (my_strcmp(argv[1], "mandel") == 0)
		return (MANDEL);
	ft_putendl_fd("Error: invalid set", STDERR_FILENO);
	ft_putendl_fd("Available fractals:\n	mandel\n	julia",
		STDERR_FILENO);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc < 2)
	{
		ft_putendl_fd("Error: fractol missing argument", STDERR_FILENO);
		ft_putendl_fd("Usage: ./fractol <fractol> [real] [imaginary]",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fract.fractal = read_input(argc, argv, &fract);
	if (fract.fractal == ERROR)
		return (EXIT_FAILURE);
	if (mlx_start(&fract.mlx, &fract.image) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop_hook(fract.mlx, &hook, &fract);
	mlx_scroll_hook(fract.mlx, &scrollhook, &fract);
	fract.l_zoom = 0;
	fract.zoom = 1;
	// fract.mouse[0] = WIN_SIZE / 2;
	// fract.mouse[1] = WIN_SIZE / 2;
	mlx_loop(fract.mlx);
	mlx_delete_image(fract.mlx, fract.image);
	mlx_terminate(fract.mlx);
}
