/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:51:34 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 08:36:09 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(int y, double a, double b)
{
	return (y * (b - a) / (WIN_SIZE) + a);
}

void	render(t_fractol *fract)
{
	if (fract->fractal == MANDEL)
		render_mendel(fract);
	else if (fract->fractal == JULIA)
		render_julia(fract, -0.8, 0.156);
	else if (fract->fractal == SHIP)
		render_ship(fract);
	else
		ft_memset(fract->image->pixels, 255,
			WIN_SIZE * WIN_SIZE * sizeof(int32_t));
}
