/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:51:34 by ecastong          #+#    #+#             */
/*   Updated: 2024/05/03 10:53:28 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_mandel(t_fractol *f, double zx, double zy)
{
	double	tmp;
	double	x;
	double	y;
	int		iterations;

	x = 0.0;
	y = 0.0;
	zx = (zx * (0.47 - (-2.0)) / (WIN_SIZE) + (-2.0)) / f->zoom;
	zy = (zy * ((-1.12) - 1.12) / (WIN_SIZE) + 1.12) / f->zoom;
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

int	iter_julia(t_fractol *f, int px, int py)
{
	int		iter;
	double	tmp;
	double	zx;
	double	zy;

	iter = 0;
	zx = (px - WIN_SIZE / 2.0) * (2 * ESC_RAD / WIN_SIZE) / f->zoom;
	zy = (py - WIN_SIZE / 2.0) * (2 * ESC_RAD / WIN_SIZE) / f->zoom;
	while (zx * zx + zy * zy < ESC_RAD * ESC_RAD && iter < MAX_ITERATIONS)
	{
		tmp = zx;
		zx = zx * zx - zy * zy + f->julia_cx;
		zy = 2 * tmp * zy + f->julia_cy;
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
			if (f->fractal == JULIA)
				iter = iter_julia(f, px, py);
			else
				iter = iter_mandel(f, px, py);
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(f->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(f->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
