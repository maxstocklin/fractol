/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:31 by mstockli          #+#    #+#             */
/*   Updated: 2022/12/08 20:52:50 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	loop_hook(t_fractol *fractol)
{
	if (fractol->color_auto == 1)
	{
		fractol->color += 10;
		draw_win(fractol);
	}
	return (0);
}

int	display_mlx_win(t_fractol *fractol)
{
	fractol->vars.mlx = mlx_init();
	if (fractol->vars.mlx != NULL)
	{
		fractol->vars.win = mlx_new_window(fractol->vars.mlx, \
		XMAX, YMAX, "CTOL-FRA");
		if (fractol->vars.win != NULL)
		{
			fractol->vars.img = mlx_new_image(fractol->vars.mlx, XMAX, YMAX);
			if (fractol->vars.img != NULL)
			{
				fractol->vars.addr = mlx_get_data_addr(fractol->vars.img, \
				&fractol->vars.bits_per_pixel, &fractol->vars.line_length, \
				&fractol->vars.endian);
				mlx_put_image_to_window(fractol->vars.mlx, fractol->vars.win, \
				fractol->vars.img, 0, 0);
				add_mlx_hook(fractol);
				mlx_loop_hook(fractol->vars.mlx, loop_hook, fractol);
				mlx_loop(fractol->vars.mlx);
				return (0);
			}
		}
	}
	return (1);
}

int	paramerror(void)
{
	write (1, "\n\nPLEASE SPECIFY THE FRACTAL YOU WANT TO SEE:\n", 46);
	write (1, "- Mandelbrot\n- Julia\n- Sierpinski\n\n", 35);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2)
	{
		if (checkinit(&fractol, av[1], -1) == 0)
			return (paramerror());
		display_mlx_win(&fractol);
	}
	else
		return (paramerror());
	return (0);
}
