/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:40:31 by ecastong          #+#    #+#             */
/*   Updated: 2024/05/04 14:35:45 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Hook used to detect scrolling input.
 * 
 * @param xdelta 
 * @param ydelta 
 * @param param void pointer to the fractol struct used 
 * to store general program data.
 */
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
		fract->update = true;
	}
	(void) xdelta;
}

/**
 * @brief Update the offset used to reder the fractal with user input.
 * 
 * @param f fractol struct containing general program data.
 */
void	update_offset(t_fractol	*f)
{
	double	scaled_sens;

	scaled_sens = SENSITIVITY / f->zoom;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->offset_x -= scaled_sens;
		f->update = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->offset_x += scaled_sens;
		f->update = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->offset_y += scaled_sens;
		f->update = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->offset_y -= scaled_sens;
		f->update = true;
	}
}

/**
 * @brief Executes actions every frames, like detecting 
 * user input or calling for the fractal to be rendered.
 * 
 * @param param void pointer to the fractol struct used 
 * to store general program data.
 */
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

/**
 * @brief Safely initialize the mlx42 structs.
 * 
 * @param mlx Address of the mlx struct to initialize.
 * @param image Address of the image struct to initialize.
 * @retval EXIT_FAILURE if either mlx or image fail to be initialized.
 * @retval EXIT_SUCCESS on success.
 */
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
