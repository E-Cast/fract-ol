/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:07:49 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 08:04:22 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		tmp = zx * zx - zy * zy;
		zy = 2 * zx * zy + cy;
		zx = tmp + cx;
		iter++;
	}
	return (iter);
}

void	render_julia(t_fractol *fract, double cx, double cy)
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
			iter = iter_julia(px, py, cx, cy);
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
