/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:51:35 by hdussert          #+#    #+#             */
/*   Updated: 2018/08/13 04:13:47 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		reset_p(t_mlx *mlx)
{
	mlx->p.min = -2;
	mlx->p.max = 2;
	mlx->p.t_a = 0;
	mlx->p.t_b = 0;
	mlx->p.ca = 0;
	mlx->p.cb = 0;
	mlx->p.abs_max = 4;
	mlx->p.n_max = 100;
	mlx->p.scale = 2.0 / mlx->size_2;
}

int			key_down(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	else if (key == 4)
		mlx->p.n_max += 10;
	else if (key == 38)
		mlx->p.n_max -= (mlx->p.n_max > 10 ? 10 : 0);
	else if (key == 15 || key == 12 || key == 13)
	{
		reset_p(mlx);
		if (key == 12)
			mlx->nfrac = (++mlx->nfrac) % (mlx->num_max + 1);
		else if (key == 13)
			mlx->nfrac = (--mlx->nfrac == -1 ? mlx->num_max : mlx->nfrac);
	}
	if (key == 126)
		mlx->p.t_b -= 20 * mlx->p.scale;
	else if (key == 125)
		mlx->p.t_b += 20 * mlx->p.scale;
	if (key == 123)
		mlx->p.t_a -= 20 * mlx->p.scale;
	else if (key == 124)
		mlx->p.t_a += 20 * mlx->p.scale;
//	if (mlx->time == 0)
//		draw(mlx);
	return (0);
}

int			mouse_down(int key, int x, int y, t_mlx *mlx)
{
	if (key == 1 && x >= 0 && y >= 0)
		mlx->p.mouse1 = 1;
	if (key == 4)
	{
		mlx->p.min /= 1.5;
		mlx->p.max /= 1.5;
		mlx->p.t_a += mlx->p.scale * (x - mlx->size_2) / 3 * 2;// / 2;
		mlx->p.t_b += mlx->p.scale * (y - mlx->size_2) / 3 * 2;// / 2;
		mlx->p.scale /= 1.5;
	}
	if (key == 5 && mlx->p.scale < 2.0 / mlx->size_2 * 2)
	{
		mlx->p.min *= 1.5;
		mlx->p.max *= 1.5;
		mlx->p.t_a += mlx->p.scale * (x - mlx->size_2) / 3 * 2;// / 2;
		mlx->p.t_b += mlx->p.scale * (y - mlx->size_2) / 3 * 2;// / 2;
		mlx->p.scale *= 1.5;
	}
//	if (mlx->time == 0)
//		draw(mlx);
	return (0);
}

int			mouse_up(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == 1)
		mlx->p.mouse1 = 0;
//	draw(mlx);
	return (0);
}

int			mouse_motion(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= mlx->size && y >= 0 && y <= mlx->size
	&& mlx->p.mouse1 == 1 && mlx->nfrac == 0)
	{
		mlx->p.ca = map(x, mlx->size, -1, 1);
		mlx->p.cb = map(y, mlx->size, -1, 1);
//		if (mlx->time == 0)
//			draw(mlx);
	}
	return (0);
}

int loop(t_mlx *mlx)
{
	mlx->time += 1;
	mlx->time %= 200;
	if (mlx->time == 0)
		draw(mlx);
	return (0);
}
