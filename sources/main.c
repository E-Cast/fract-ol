/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/05/04 18:59:52 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Handles user input like selecting which fractal or set to use.
 * 
 * @param argc Number of argument.
 * @param argv Arguments.
 * @param fract Struct containing 
 * @retval EXIT_FAILURE if arguments are invalid.
 * @retval EXIT_SUCCESS on success.
 */
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
		fract->fractal = JULIA;
		return (EXIT_SUCCESS);
	}
	else if (my_strcmp(argv[1], "mandel") == 0)
	{
		if (argc > 2)
			return (ft_putendl_fd("Error: too many arguments for mandel",
					STDERR_FILENO), EXIT_FAILURE);
		fract->fractal = MANDEL;
		return (EXIT_SUCCESS);
	}
	ft_putendl_fd("Error: invalid fractal name", STDERR_FILENO);
	ft_putendl_fd("Available fractals:\n	mandel\n	julia",
		STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc < 2 || argc > 4)
	{
		if (argc < 2)
			ft_putendl_fd("Error: not enough arguments", STDERR_FILENO);
		if (argc > 4)
			ft_putendl_fd("Error: too many arguments", STDERR_FILENO);
		ft_putendl_fd("Usage: ./fractol <fractal> [real] [imaginary]",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (read_input(argc, argv, &fract) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (mlx_start(&fract.mlx, &fract.image) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fract.update = true;
	fract.zoom = 1;
	fract.offset_x = 0;
	fract.offset_y = 0;
	mlx_loop_hook(fract.mlx, &hook, &fract);
	mlx_scroll_hook(fract.mlx, &scrollhook, &fract);
	mlx_loop(fract.mlx);
	mlx_delete_image(fract.mlx, fract.image);
	mlx_terminate(fract.mlx);
}
