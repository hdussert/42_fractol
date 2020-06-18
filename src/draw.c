/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:25:41 by hdussert          #+#    #+#             */
/*   Updated: 2018/08/13 03:49:13 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void						draw_julia(t_mlx *mlx)
{
	t_draw_params	d;

	d.y = -1;
	while (++d.y < mlx->size)
	{
		d.x = -1;
		while (++d.x < mlx->size)
		{
			d.a = map(d.x, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_a;
			d.b = map(d.y, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_b;
			d.fa = mlx->p.ca;
			d.fb = mlx->p.cb;
			d.n = -1;
			while (++d.n < mlx->p.n_max && (d.sqr_a = d.a * d.a)
					+ (d.sqr_b = d.b * d.b) < mlx->p.abs_max)
			{
				d.b = (d.a + d.a) * d.b + d.fb;
				d.a = d.sqr_a - d.sqr_b + d.fa;
			}
			d.color = (d.n == mlx->p.n_max ? 0 : calc_color(d.n));
			((unsigned int *)mlx->image->img)[d.x + d.y * mlx->size] = d.color;
		}
	}
}

void						draw_mandelbrot(t_mlx *mlx)
{
	t_draw_params	d;

	d.y = -1;
	while (++d.y < mlx->size)
	{
		d.x = -1;
		while (++d.x < mlx->size)
		{
			d.a = map(d.x, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_a;
			d.b = map(d.y, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_b;
			d.fa = d.a;
			d.fb = d.b;
			d.n = -1;
			while (++d.n < mlx->p.n_max && (d.sqr_a = d.a * d.a)
					+ (d.sqr_b = d.b * d.b) < mlx->p.abs_max)
			{
				d.b = (d.a + d.a) * d.b + d.fb;
				d.a = d.sqr_a - d.sqr_b + d.fa;
			}
			d.color = (d.n == mlx->p.n_max ? 0 : calc_color(d.n));
			((unsigned int *)mlx->image->img)[d.x + d.y * mlx->size] = d.color;
		}
	}
}

void						draw_burningship(t_mlx *mlx)
{
	t_draw_params	d;

	d.y = -1;
	while (++d.y < mlx->size)
	{
		d.x = -1;
		while (++d.x < mlx->size)
		{
			d.a = map(d.x, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_a;
			d.b = map(d.y, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_b;
			d.fa = d.a;
			d.fb = d.b;
			d.n = -1;
			while (++d.n < mlx->p.n_max && (d.sqr_a = d.a * d.a)
					+ (d.sqr_b = d.b * d.b) < mlx->p.abs_max)
			{
				d.b = fabsl((d.a + d.a) * d.b) + d.fb;
				d.a = fabsl((d.sqr_a - d.sqr_b) + d.fa);
			}
			d.color = (d.n == mlx->p.n_max ? 0 : calc_color(d.n));
			((unsigned int *)mlx->image->img)[d.x + d.y * mlx->size] = d.color;
		}
	}
}

void						draw_tricorn(t_mlx *mlx)
{
	t_draw_params	d;

	d.y = -1;
	while (++d.y < mlx->size)
	{
		d.x = -1;
		while (++d.x < mlx->size)
		{
			d.a = map(d.x, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_a;
			d.b = map(d.y, mlx->size, mlx->p.min, mlx->p.max) + mlx->p.t_b;
			d.fa = d.a;
			d.fb = d.b;
			d.n = -1;
			while (++d.n < mlx->p.n_max && (d.sqr_a = d.a * d.a)
					+ (d.sqr_b = d.b * d.b) < mlx->p.abs_max)
			{
				d.b = -((d.a + d.a) * d.b) + d.fb;
				d.a = d.sqr_a - d.sqr_b + d.fa;
			}
			d.color = (d.n == mlx->p.n_max ? 0 : calc_color(d.n));
			((unsigned int *)mlx->image->img)[d.x + d.y * mlx->size] = d.color;
		}
	}
}

void						draw(t_mlx *mlx)
{
	if (mlx->nfrac == 0)
		draw_julia(mlx);
	else if (mlx->nfrac == 1)
		draw_mandelbrot(mlx);
	else if (mlx->nfrac == 2)
		draw_burningship(mlx);
	else if (mlx->nfrac == 3)
		draw_tricorn(mlx);
	((unsigned int *)mlx->image->img)[mlx->size / 2 + mlx->size / 2
		* mlx->size] = 0xFF00FF;
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->ptr, 0, 0);
	mlx_string_put(mlx->mlx, mlx->window, 20, 20, 0xFFFFFF, "Increase n: H");
	mlx_string_put(mlx->mlx, mlx->window, 20, 40, 0xFFFFFF, "Decrease n: J");
	mlx_string_put(mlx->mlx, mlx->window, 20, 60, 0xFFFFFF,
												"Left/Right/Up/Down to moove");
	mlx_string_put(mlx->mlx, mlx->window, 20, 80, 0xFFFFFF,
												"Scroll to zoom in/out");
}
