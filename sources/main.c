/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:19:46 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/24 16:10:40 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	calculate_pixel(t_fractol	fract, int sx, int sy)
// {
// 	double	x;
// 	double	y;
// 	double	tmp;
// 	int		i;
// 	// size_t	color;

// 	// x = WIN_WIDTH + sx - WIN_WIDTH / 2.;
// 	// y = WIN_HEIGHT + sy - WIN_HEIGHT / 2.;
// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	while (mod2(x, y) < 4. && i < 100)//
// 	{
// 		tmp = x;
// 		x = tmp * tmp - y * y - 1.;
// 		y = 2. * tmp * y;
// 		i++;
// 		// printf("%i\n", i);
// 	}
// 	if (i == 100)
// 	{
// 		printf("black\n");
// 		mlx_put_pixel(fract.image, sx, sy, 0x000000FF);
// 	}
// 	else
// 	{
// 		printf("%i\n", i);
// 		// printf("white\n");
// 		mlx_put_pixel(fract.image, sx, sy, 0xFFFFFFFF);
// 	}
// }

// void	calculate(t_fractol	fract, int sx, int sy)
// {
// 	int		i;
// 	double	x;
// 	double	y;
// 	double	tmp;

// 	i = 0;
// 	x = 0.0;
// 	y = 0.0;
// 	while (++i < 100)
// 	{
// 		tmp = x;
// 		x = x * x - y * y + sx;
// 		y = 2. * tmp * y + sy;
// 		if (x * x + y * y >= __DBL_MAX__)
// 		{
// 			printf("brk\n");
// 			break ;
// 		}
// 	}
// 	if (i == 100)
// 		mlx_put_pixel(fract.image, sx, sy, 0x000000FF);
// 	else
// 		mlx_put_pixel(fract.image, sx, sy, 0xFFFFFFFF);
// 	printf("%i\n", i);
// }






double	mod2(double x, double y)
{
	return (x * x + y * y);
}

t_vec2	compute_next(t_vec2 current, t_vec2 constant)
{
	double	zr;
	double	zi;

	zr = current.x * current.x - current.y;
	zi = 2.0 * current.x * current.y;
	current.x = zr + constant.x;
	current.y = zi + constant.y;
	return (current);
}

int	compute_iterations(t_vec2 z0, t_vec2 constant)
{
	t_vec2	zn;
	int		i;

	zn = z0;
	i = 0;
	while (mod2(zn.x, zn.y) <= 4.0 && i < MAX_ITERATIONS)
	{
		zn = compute_next(zn, constant);
		i++;
	}
	return (i);
}

void	render_fractal(t_fractol fract, t_ivec2 render_size, t_vec2 constant)
{
	double	scale;
	int		y;
	int		x;
	double	px;
	double	py;
	double	iterations;
	t_vec2	tmp;

	scale = 1.0f / (double)(render_size.y / 2);
	y = 0;
	while (y < render_size.y)
	{
		x = 0;
		while (x < render_size.x)
		{
			px = (double)(x - render_size.x / 2) * scale;
			py = (double)(y - render_size.y / 2) * scale;
			tmp.x = px;
			tmp.y = py;
			iterations = compute_iterations( tmp, constant);
			if (iterations == 50)
				mlx_put_pixel(fract.image, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(fract.image, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	printf("done\n");
	mlx_image_to_window(fract.mlx, fract.image, 0, 0);
}

// void	draw_fractal(t_fractol	fract)
// {
// 	int	sx;
// 	int	sy;

// 	sx = 0;
// 	while (sx < WIN_WIDTH)
// 	{
// 		sy = 0;
// 		while (sy < WIN_HEIGHT)
// 		{
// 			calculate_pixel(fract, sx, sy);
// 			sy++;
// 		}
// 		sx++;
// 	}
// 	mlx_image_to_window(fract.mlx, fract.image, 0, 0);
// }

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
	mlx_loop_hook(fract.mlx, &keyhook, &fract);
	mlx_scroll_hook(fract.mlx, &scrollhook, NULL);

	t_ivec2 size = {WIN_WIDTH, WIN_HEIGHT};
	t_vec2	constant = {0.0, 1};
	render_fractal(fract, size, constant);
	mlx_loop(fract.mlx);
	//calculate pixel using formula function
	//calculate every pixel function
	//move functions
	//clear function
	mlx_delete_image(fract.mlx, fract.image);
	mlx_terminate(fract.mlx);
}
