/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:06:38 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 08:39:33 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		tmp = x * x - y * y + zx;
		y = 2 * x * y + zy;
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

	px = 0;
	while (px < WIN_SIZE)
	{
		py = 0;
		while (py < WIN_SIZE)
		{
			iter = iter_mandel(scale(px, -2.0, 0.47), scale(py, -1.12, 1.12));
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, PALETTE * iter);
			py++;
		}
		px++;
	}
}
