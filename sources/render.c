/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:51:34 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 07:07:25 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractol *fract)
{
	if (fract->fractal == MANDEL)
		render_mendel(fract);
	else if (fract->fractal == JULIA)
		render_julia(fract, -0.8, 0.156);
	else
		ft_memset(fract->image->pixels, 255,
			WIN_WIDTH * WIN_HEIGHT * sizeof(int32_t));
}
