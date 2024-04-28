/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:23:43 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 08:18:29 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	iter_ship(double zx, double zy, double x, double y)
// {
// 	int		iter;
// 	double	tmp;

// 	iter = 0;
// 	while (zx * zx + zy * zy < ESC_RAD * ESC_RAD && iter < MAX_ITERATIONS)
// 	{
// 		tmp = fabs(zx) * fabs(zx) - fabs(zy) * fabs(zy) + x;
// 		zy = 2 * fabs(zx) * fabs(zy) + y;
// 		zx = tmp;
// 		iter++;
// 	}
// 	return (iter);
// }

// void	render_ship(t_fractol *fract)
// {
// 	int		px;
// 	int		py;
// 	int		iter;
// 	double	x_scale;
// 	double	y_scale;
// 	double	x;
// 	double	y;

// 	px = 0;
// 	x_scale = (1 - (-2.5)) / (WIN_SIZE);
// 	y_scale = (1 - (-1)) / (WIN_SIZE);
// 	while (px < WIN_SIZE)
// 	{
// 		py = 0;
// 		while (py < WIN_SIZE)
// 		{
// 			x = px * x_scale - 2.5;
// 			y = py * y_scale - 1;
// 			iter = iter_ship(x, y, x, y);
// 			if (iter == MAX_ITERATIONS)
// 				mlx_put_pixel(fract->image, px, py, 0x000000FF);
// 			else
// 				mlx_put_pixel(fract->image, px, py, PALETTE * iter);
// 			py++;
// 		}
// 		px++;
// 	}
// }

int	iter_ship(double x, double y)
{
	double	zx;
	double	zy;
	int		iter;
	double	tmp;

	zx = x;
	zy = y;
	iter = 0;
	while (zx * zx + zy * zy < ESC_RAD * ESC_RAD && iter < MAX_ITERATIONS)
	{
		tmp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = tmp;
		iter++;
	}
	return (iter);
}

void	render_ship(t_fractol *fract)
{
	int		px;
	int		py;
	int		iter;
	double	scaled_x;
	double	scaled_y;

	px = 0;
	while (px < WIN_SIZE)
	{
		py = 0;
		while (py < WIN_SIZE)
		{
			scaled_x = px * (1 - (-2.50)) / (WIN_SIZE * fract->zoom) - 2.50;
			scaled_y = py * (1 - (-2.50)) / (WIN_SIZE * fract->zoom) - 2.50;
			// scaled_x = (double)px / WIN_SIZE * 3.5 - 1.5;
			// scaled_y = (double)py / WIN_SIZE * 3.5 - 2.5;
			iter = iter_ship(scaled_x, scaled_y);
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
