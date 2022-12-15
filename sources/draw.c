/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:52:26 by mstockli          #+#    #+#             */
/*   Updated: 2022/12/15 11:53:54 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	int		*img;

	img = (int *)fractol->vars.addr;
	if (x >= 0 && x < XMAX && y >= 0 && y < YMAX)
		img[x + XMAX * y] = color;
}

int	convert_base(int itermod, int red, int green, int blue)
{
	itermod = itermod % 255;
	while (green < 255 && itermod-- > 0)
		green += 5;
	while (red > 0 && itermod-- > 0)
		red -= 5;
	while (blue < 255 && itermod-- > 0)
		blue += 5;
	while (green > 0 && itermod-- > 0)
		green -= 5;
	while (red < 255 && itermod-- > 0)
		red += 5;
	return (0 << 24 | red << 16 | green << 8 | blue);
}

int	fade(uint32_t itered, uint32_t max_iter, t_fractol *fractol)
{
	if (itered == max_iter)
	{
		if (fractol->rand_color == 1)
			return (0 << 16 | 0 << 8 | 0);
		return (rand() % 255 << 16 | rand() % 255 << 8 | rand() % 255);
	}
	else if (ft_strcmp(fractol->name, "sierpinski") == 0)
	{
		fractol->sip_color = rand() % 200;
		itered = itered + fractol->color;
	}
	else
		itered = itered + fractol->color;
	return (convert_base(itered, 255, 0, 0));
}

int	iter_fractal(t_fractol *fractol, t_vector pix)
{
	if (ft_strcmp(fractol->name, "mandelbrot") == 0)
		return (draw_mandelbrot(fractol, pix));
	else if (ft_strcmp(fractol->name, "julia") == 0)
		return (draw_julia(fractol, pix));
	else
		return (draw_sierpinski(fractol, pix));
}

void	draw_win(t_fractol *fractol)
{
	int			itered;
	int			color;
	t_vector	pix;

	mlx_clear_window(fractol->vars.mlx, fractol->vars.win);
	pix.y = 0;
	while (pix.y < YMAX)
	{
		pix.x = 0;
		while (pix.x < XMAX)
		{
			itered = iter_fractal(fractol, pix);
			color = fade(itered, fractol->max_iter, fractol);
			put_pixel(fractol, pix.x, pix.y, color);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(fractol->vars.mlx, \
	fractol->vars.win, fractol->vars.img, 0, 0);
}
