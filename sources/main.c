/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/24 16:57:37 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double	mod2(double x, double y)
// {
// 	return (x * x + y * y);
// }

// t_vec2	compute_next(t_vec2 current, t_vec2 constant)
// {
// 	double	zr;
// 	double	zi;

// 	zr = current.x * current.x - current.y;
// 	zi = 2.0 * current.x * current.y;
// 	current.x = zr + constant.x;
// 	current.y = zi + constant.y;
// 	return (current);
// }

// int	compute_iterations(t_vec2 z0, t_vec2 constant)
// {
// 	t_vec2	zn;
// 	int		i;

// 	zn = z0;
// 	i = 0;
// 	while (mod2(zn.x, zn.y) <= 4.0 && i < MAX_ITERATIONS)
// 	{
// 		zn = compute_next(zn, constant);
// 		i++;
// 	}
// 	return (i);
// }

void	render(t_fractol *fract)
{
	ft_memset(fract->image->pixels, 255,
		WIN_WIDTH * WIN_HEIGHT * sizeof(int32_t));
}

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
		return (EXIT_FAILURE);
	fract.fractal = read_input(argv[1]);
	if (fract.fractal == ERROR)
		return (EXIT_FAILURE);
	if (mlx_start(&fract.mlx, &fract.image) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop_hook(fract.mlx, &hook, &fract);
	mlx_scroll_hook(fract.mlx, &scrollhook, NULL);
	mlx_loop(fract.mlx);
	mlx_delete_image(fract.mlx, fract.image);
	mlx_terminate(fract.mlx);
}
