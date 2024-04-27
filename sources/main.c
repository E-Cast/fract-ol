/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/27 08:46:55 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	read_input(char *arg)
{
	if (my_strcmp(arg, "mandel") == 0)
		return (MANDEL);
	else if (my_strcmp(arg, "julia") == 0)
		return (JULIA);
	else if (my_strcmp(arg, "ship") == 0)
		return (SHIP);
	else if (my_strcmp(arg, "newton") == 0)
		return (NEWTON);
	ft_putendl_fd("Error: invalid set", STDERR_FILENO);
	ft_putendl_fd("Available sets:\n	mandel\n	julia\n	ship\n	newton",
		STDERR_FILENO);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc != 2)
	{
		ft_putendl_fd("Error: fractol missing argument", STDERR_FILENO);
		ft_putendl_fd("Usage: ./fractol <set>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fract.fractal = read_input(argv[1]);
	if (fract.fractal == ERROR)
		return (EXIT_FAILURE);
	if (mlx_start(&fract.mlx, &fract.image) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop_hook(fract.mlx, &hook, &fract);
	mlx_scroll_hook(fract.mlx, &scrollhook, &fract);
	fract.l_zoom = 0;
	fract.zoom = 1;
	fract.mouse[0] = WIN_WIDTH / 2;
	fract.mouse[1] = WIN_HEIGHT / 2;
	mlx_loop(fract.mlx);
	mlx_delete_image(fract.mlx, fract.image);
	mlx_terminate(fract.mlx);
}
