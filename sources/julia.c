/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:07:49 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 06:53:04 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//call render_julia(fract, 2.0, -0.8, 0.156);
void	render_julia(t_fractol *fract, double R, double cx, double cy)
{
	int		px;
	int		py;
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	px = 0;
	while (px < WIN_WIDTH)
	{
		py = 0;
		while (py < WIN_HEIGHT)
		{
			iter = 0;
			zx = (px - WIN_WIDTH / 2.0) * (2 * R / WIN_WIDTH) * WIN_WIDTH / WIN_HEIGHT;
			zy = (py - WIN_HEIGHT / 2.0) * (2 * R / WIN_HEIGHT);
			while (zx * zx + zy * zy < R * R && iter < MAX_ITERATIONS)
			{
				tmp = zx * zx - zy * zy;
				zy = 2 * zx * zy + cy;
				zx = tmp + cx;
				iter++;
			}
			if (iter == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, 0xFCBE11FF * iter);
			py++;
		}
		px++;
	}
}
