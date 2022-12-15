/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:40:22 by mstockli          #+#    #+#             */
/*   Updated: 2022/12/06 18:17:01 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *fractol, t_vector pix)
{
	fractol->pos.x += fractol->size.x / 3 * (pix.x / (double)XMAX);
	fractol->pos.y += fractol->size.y / 3 * (pix.y / (double)YMAX);
	fractol->size.x -= fractol->size.x / 3;
	fractol->size.y -= fractol->size.y / 3;
}

void	zoom_out(t_fractol *fractol, t_vector pix)
{
	fractol->pos.x -= fractol->size.x / 3 * (pix.x / (double)XMAX);
	fractol->pos.y -= fractol->size.y / 3 * (pix.y / (double)YMAX);
	fractol->size.x += fractol->size.x / 3;
	fractol->size.y += fractol->size.y / 3;
}
