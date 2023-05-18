/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:55:30 by mstockli          #+#    #+#             */
/*   Updated: 2023/05/18 18:50:22 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == RETURN_KEY)
	{
		fractol->color_auto *= -1;
		fractol->max_iter = 300;
		if (fractol->color_auto == 1)
			fractol->max_iter = 100;
	}
	else if (keycode < 21 && keycode > 17)
		checkinit(fractol, "hello", keycode % 18);
	else if (keycode == TAB_KEY)
		fractol->rand_color *= -1;
	else if (keycode == SPACE_KEY)
		fractol->color += 60;
	else if (keycode == MINUS_KEY)
		zoom_out(fractol, (t_vector){XMAX / 2, YMAX / 2});
	else if (keycode == PLUS_KEY)
		zoom_in(fractol, (t_vector){XMAX / 2, YMAX / 2});
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		fractol->pos.x -= (fractol->size.x / 10) * (pow(-1, keycode));
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW)
		fractol->pos.y += (fractol->size.x / 10) * (pow(-1, keycode));
	draw_win(fractol);
	return (0);
}

int	scroll_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == SCROLLDOWN_KEY)
		zoom_out(fractol, (t_vector){x, y});
	else if (button == SCROLLUP_KEY)
		zoom_in(fractol, (t_vector){x, y});
	else
	{
		if (!fractol->movable && button == LEFT_CLICK)
		{
			fractol->drag = 1;
			fractol->bpos.x = x;
			fractol->bpos.y = y;
		}
	}
	draw_win(fractol);
	return (0);
}

int	drop_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (!fractol->movable && button == LEFT_CLICK)
		fractol->drag = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->movable)
	{
		fractol->mouse_pos.x = (((double)x / (double)XMAX) \
		* fractol->size.x + fractol->pos.x);
		fractol->mouse_pos.y = (((double)y / (double)YMAX) \
		* fractol->size.y + fractol->pos.y);
		draw_win(fractol);
	}
	else if (fractol->drag == 1 && !fractol->movable)
	{
		fractol->pos.y = fractol->pos.y - \
		((((y - fractol->bpos.y) / YMAX) * fractol->size.y));
		fractol->bpos.y = y;
		fractol->pos.x = fractol->pos.x - \
		((((x - fractol->bpos.x) / XMAX) * fractol->size.x));
		fractol->bpos.x = x;
		draw_win(fractol);
	}
	return (0);
}

void	add_mlx_hook(t_fractol *fractol)
{
	mlx_hook(fractol->vars.win, KEYPRESS, 0, key_hook, fractol);
	mlx_hook(fractol->vars.win, MOUSEMOVE, 0, mouse_hook, fractol);
	mlx_hook(fractol->vars.win, MOUSEPRESS, 0, scroll_hook, fractol);
	mlx_hook(fractol->vars.win, MOUSERELEASE, 0, drop_hook, fractol);
	mlx_hook(fractol->vars.win, DESTROYNOTIFY, 0, fractol_exit, fractol);
}
