/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:40:31 by ecastong          #+#    #+#             */
/*   Updated: 2024/05/03 11:32:12 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (ydelta != 0)
	{
		fract->update = true;
		if (ydelta > 0)
			fract->zoom = fract->zoom * 2;
		else
			fract->zoom = fract->zoom / 2;
	}
	(void) xdelta;
}

void	update_offset(t_fractol	*f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->offset_x -= SENSITIVITY;
		f->update = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->offset_x += SENSITIVITY;
		f->update = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->offset_y += SENSITIVITY;
		f->update = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->offset_y -= SENSITIVITY;
		f->update = true;
	}
}

void	hook(void *param)
{
	t_fractol	*fract;
	mlx_t		*mlx;

	fract = (t_fractol *)param;
	mlx = fract->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	update_offset(fract);
	if (fract->update == true)
	{
		render(fract);
		if (mlx_image_to_window(mlx, fract->image, 0, 0) < 0)//
		{
			ft_putendl_fd("Error: failed to display image to window",
				STDERR_FILENO);
			mlx_close_window(mlx);
		}
		fract->update = false;
	}
}

int	mlx_start(mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(WIN_SIZE, WIN_SIZE, "fractol", 0);
	if (!*mlx)//
		return (EXIT_FAILURE);
	*image = mlx_new_image(*mlx, WIN_SIZE, WIN_SIZE);
	if (!*image)//
		return (mlx_terminate(*mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
