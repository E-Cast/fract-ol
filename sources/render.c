/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:51:34 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 07:23:31 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
