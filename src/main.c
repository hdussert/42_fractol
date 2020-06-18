/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 13:20:21 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/07 16:11:20 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*new_image(t_mlx *mlx)
{
	t_image		*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		exit(1);
	img->ptr = mlx_new_image(mlx->mlx, mlx->size, mlx->size);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l, &img->endian);
	return (img);
}

t_mlx		*new_mlx(int size, char *name)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		exit(1);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, size, size, name);
	mlx->size = size;
	mlx->size_2 = size / 2.0;
	mlx->image = new_image(mlx);
	mlx->nfrac = -1;
	mlx->num_max = 3;
	mlx->time = 0;
	reset_p(mlx);
	return (mlx);
}

int			main(int argc, char *argv[])
{
	t_mlx			*mlx;

	if (argc == 2)
	{
		mlx = new_mlx(750, "fractol");
		mlx->nfrac = (ft_strcmp(argv[1], "Julia") == 0 ? 0 : mlx->nfrac);
		mlx->nfrac = (ft_strcmp(argv[1], "Mandelbrot") == 0 ? 1 : mlx->nfrac);
		mlx->nfrac = (ft_strcmp(argv[1], "BurningShip") == 0 ? 2 : mlx->nfrac);
		mlx->nfrac = (ft_strcmp(argv[1], "Tricorn") == 0 ? 3 : mlx->nfrac);
		if (mlx->nfrac == -1)
		{
			free(mlx);
			usage();
			return (0);
		}
		draw(mlx);
		mlx_hook(mlx->window, 2, 0, key_down, mlx);
		mlx_hook(mlx->window, 4, 0, mouse_down, mlx);
		mlx_hook(mlx->window, 5, 0, mouse_up, mlx);
		mlx_hook(mlx->window, 6, 0, mouse_motion, mlx);
		mlx_loop_hook(mlx->mlx, loop, mlx);
		mlx_loop(mlx->mlx);
	}
	else
		usage();
	return (0);
}
