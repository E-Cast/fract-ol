/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:06:38 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 07:19:56 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iteration_count(double x0, double y0)
{
	double	tmp;
	double	x;
	double	y;
	int		iterations;

	x = 0.0;
	y = 0.0;
	iterations = 0;
	//4.0 == escape radius * escape radius?
	while (x * x + y * y <= 4.0 && iterations < MAX_ITERATIONS)
	{
		tmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmp;
		iterations++;
	}
	return (iterations);
}

void	render_mendel(t_fractol *fract)
{
	int		px;
	int		py;
	int		iter;
	double	x0;
	double	y0;
	double	x_scale;
	double	y_scale;
	double	center_x;
	double	center_y;

	px = 0;
	center_x = 0;
	center_y = 0;
	center_y = 0;
	x_scale = (0.47 - (-2.00)) / (WIN_SIZE * fract->zoom);
	y_scale = (1.12 - (-1.12)) / (WIN_SIZE * fract->zoom);
	while (px < WIN_SIZE)
	{
		py = 0;
		while (py < WIN_SIZE)
		{
			x0 = px * x_scale - 2.00 + center_x;
			y0 = py * y_scale - 1.12 + center_y;
			iter = get_iteration_count(x0, y0);
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
