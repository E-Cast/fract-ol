/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:23:43 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:05 by ecastong         ###   ########.fr       */
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

	px = 0;
	while (px < WIN_SIZE)
	{
		py = 0;
		while (py < WIN_SIZE)
		{
			iter = iter_ship(scale(px, -2.5, 1.0), scale(py, -2.5, 1.0));
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
