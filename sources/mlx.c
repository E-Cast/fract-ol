/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:40:31 by ecastong          #+#    #+#             */
/*   Updated: 2024/04/28 07:20:12 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (ydelta != 0)
		fract->zoom += ydelta / ZOOM_STRENGTH;
	(void) xdelta;
}

void	hook(void *param)
{
	t_fractol	*fract;
	mlx_t		*mlx;

	fract = (t_fractol *)param;
	mlx = fract->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (fract->zoom != fract->l_zoom)
	{
		fract->l_zoom = fract->zoom;
		fract->l_mouse[0] = fract->mouse[0];
		fract->l_mouse[1] = fract->mouse[1];
		mlx_get_mouse_pos(fract->mlx, &fract->mouse[0], &fract->mouse[1]);
		render(fract);
		if (mlx_image_to_window(mlx, fract->image, 0, 0) < 0)
		{
			ft_putendl_fd("Error: failed to display image to window",
				STDERR_FILENO);
			mlx_close_window(mlx);
		}
	}
}

int	mlx_start(mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(WIN_SIZE, WIN_SIZE, "fractol", 0);
	if (!*mlx)
		return (EXIT_FAILURE);
	*image = mlx_new_image(*mlx, WIN_SIZE, WIN_SIZE);
	if (!*image)
		return (mlx_terminate(*mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
