/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:51:34 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/25 06:19:30 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mendel(t_fractol *fract)
{
	int		px;
	int		py;
	double	x0;
	double	y0;
	double	x_scale;
	double	y_scale;
	double	x;
	double	y;
	double	tmp;
	int		i;

	px = 0;
	x_scale = (0.47 - (-2.00)) / (WIN_WIDTH * fract->zoom);
	y_scale = (1.12 - (-1.12)) / (WIN_HEIGHT * fract->zoom);
	while (px < WIN_WIDTH)
	{
		py = 0;
		while (py < WIN_HEIGHT)
		{
			x0 = px * x_scale - 2.00;
			y0 = py * y_scale - 1.12;
			x = 0.0;
			y = 0.0;
			i = 0;
			while (x * x + y * y <= 4.0 && i < MAX_ITERATIONS)
			{
				tmp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = tmp;
				i++;
			}
			if (i == MAX_ITERATIONS)
				mlx_put_pixel(fract->image, px, py, 0x000000FF);
			else
				mlx_put_pixel(fract->image, px, py, 0xFCBE11FF * i);
			py++;
		}
		px++;
	}
}

void	render(t_fractol *fract)
{
	if (fract->fractal == MANDEL)
		render_mendel(fract);
	else
		ft_memset(fract->image->pixels, 255,
			WIN_WIDTH * WIN_HEIGHT * sizeof(int32_t));
}
