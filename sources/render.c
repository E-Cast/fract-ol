/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:51:34 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 09:21:44 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(int y, double a, double b)
{
	return (y * (b - a) / (WIN_SIZE) + a);
}

int	iter_julia(int px, int py, double cx, double cy)
{
	int		iter;
	double	tmp;
	double	zx;
	double	zy;

	iter = 0;
	zx = (px - WIN_SIZE / 2.0) * (2 * ESC_RAD / WIN_SIZE);
	zy = (py - WIN_SIZE / 2.0) * (2 * ESC_RAD / WIN_SIZE);
	while (zx * zx + zy * zy < ESC_RAD * ESC_RAD && iter < MAX_ITERATIONS)
	{
		tmp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * tmp * zy + cy;
		iter++;
	}
	return (iter);
}

int	iter_mandel(double zx, double zy)
{
	double	tmp;
	double	x;
	double	y;
	int		iterations;

	x = 0.0;
	y = 0.0;
	iterations = 0;
	while (x * x + y * y <= ESC_RAD * ESC_RAD && iterations < MAX_ITERATIONS)
	{
		tmp = x;
		x = x * x - y * y + zx;
		y = 2 * tmp * y + zy;
		iterations++;
	}
	return (iterations);
}

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
		tmp = zx;
		zx = zx * zx - zy * zy + x;
		zy = fabs(2 * tmp * zy) + y;
		iter++;
	}
	return (iter);
}

void	render(t_fractol *f)
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
			if (f->fractal == MANDEL)
				iter = iter_mandel(scale(px, -2.0, 0.47),
						scale(py, -1.12, 1.12));
			else if (f->fractal == JULIA)
				iter = iter_julia(px, py, f->julia_cx, f->julia_cy);
			else
				iter = iter_ship(scale(px, -2.5, 1.0), scale(py, -2.5, 1.0));
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(f->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(f->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
