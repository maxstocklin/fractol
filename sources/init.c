/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:28 by mstockli          #+#    #+#             */
/*   Updated: 2022/12/08 20:57:56 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	init_mandel(t_fractol *fractol)
{
	fractol->name = "mandelbrot";
	fractol->color_auto = 1;
	fractol->size.x = 2.7;
	fractol->size.y = 2.4;
	fractol->pos.x = -2.1;
	fractol->pos.y = -1.2;
	fractol->max_iter = 100;
	fractol->movable = false;
	fractol->color = 0;
	fractol->rand_color = 1;
	fractol->drag = 0;
	return (1);
}

int	init_julia(t_fractol *fractol)
{
	fractol->name = "julia";
	fractol->color_auto = -1;
	fractol->size.x = 4.0;
	fractol->size.y = 4.0;
	fractol->pos.x = -2.0;
	fractol->pos.y = -2.0;
	fractol->max_iter = 200;
	fractol->movable = true;
	fractol->mov_lock = false;
	fractol->color = 0;
	fractol->rand_color = 1;
	return (1);
}

int	init_sierpinski(t_fractol *fractol)
{
	fractol->name = "sierpinski";
	fractol->color_auto = 1;
	fractol->size.x = 9.0;
	fractol->size.y = 9.0;
	fractol->pos.x = 0.0;
	fractol->pos.y = 0.0;
	fractol->max_iter = 500;
	fractol->movable = false;
	fractol->color = 0;
	fractol->rand_color = 1;
	return (1);
}

int	checkinit(t_fractol *fractol, char *param, int mod)
{
	if (ft_strcmp("Mandelbrot", param) == 0 || mod == 0)
		return (init_mandel(fractol));
	else if (ft_strcmp("Julia", param) == 0 || mod == 1)
		return (init_julia(fractol));
	else if (ft_strcmp("Sierpinski", param) == 0 || mod == 2)
		return (init_sierpinski(fractol));
	return (0);
}
