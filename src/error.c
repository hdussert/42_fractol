/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:42:31 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/02 14:49:29 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <unistd.h>

static void	ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

void		usage(void)
{
	ft_puterror("usage: ./fractol [fractale]\n");
	ft_puterror("Fractales:\n- Mandelbrot\n- Julia\n- blah\n");
}
