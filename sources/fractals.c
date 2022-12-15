/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:21:22 by mstockli          #+#    #+#             */
/*   Updated: 2022/12/08 19:09:56 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_julia(t_fractol *fractol, t_vector pix)
{
	t_math	z;
	int		iter;
	double	tmp;

	z.r = pix.x / (XMAX / fractol->size.x) + fractol->pos.x;
	z.i = pix.y / (YMAX / fractol->size.y) + fractol->pos.y;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < fractol->max_iter)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + fractol->mouse_pos.x;
		z.i = (2 * z.i * tmp) + fractol->mouse_pos.y;
		iter++;
	}
	return (iter);
}

double	ft_double_abs(double nbr)
{
	if (nbr > 0)
		return (nbr);
	return (-nbr);
}

int	draw_sierpinski(t_fractol *fractol, t_vector pix)
{
	t_vector	base_point;
	int			iter;

	base_point.x = ft_double_abs(pix.x \
	/ (XMAX / fractol->size.x) + fractol->pos.x);
	base_point.y = ft_double_abs(pix.y \
	/ (YMAX / fractol->size.y) + fractol->pos.y);
	iter = 0;
	while (iter < fractol->max_iter)
	{
		if ((int)base_point.x % 3 == 1 && (int)base_point.y % 3 == 1)
			return (iter);
		base_point.x *= 3;
		base_point.y *= 3;
		iter++;
	}
	return (iter);
}

int	draw_mandelbrot(t_fractol *fractol, t_vector pix)
{
	t_math	base_point;
	t_math	z;
	int		iter;
	double	tmp;

	z.r = pix.x / (XMAX / fractol->size.x) + fractol->pos.x;
	z.i = pix.y / (YMAX / fractol->size.y) + fractol->pos.y;
	base_point = z;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < fractol->max_iter)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + base_point.r;
		z.i = (2 * z.i * tmp) + base_point.i;
		iter++;
	}
	return (iter);
}
