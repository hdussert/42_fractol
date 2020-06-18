/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:27:33 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 13:32:27 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline long double	map(long double v, long double v_e,
						long double r_s, long double r_e)
{
	return (v / v_e * (r_e - r_s) + r_s);
}

inline int			calc_color(long double n)
{
	return (((int)(sin(0.3 * n) * 127 + 128) << 16) |
			((int)(sin(0.2 * n + (M_PI / 3) * 2) * 127 + 128) << 8) |
			((int)(sin(0.1 * n + (M_PI / 3) * 4) * 127 + 128)));
}
