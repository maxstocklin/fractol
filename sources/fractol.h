/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:16:01 by mstockli          #+#    #+#             */
/*   Updated: 2022/12/08 21:56:25 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_math
{
	double		r;
	double		i;
}				t_math;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_vars
{
	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

typedef struct s_fractol
{
	t_vars		vars;
	t_vector	mouse_pos;
	int			color;
	int			rand_color;
	int			color_auto;
	int			sip_color;

	int			drag;
	t_vector	bsize;
	t_vector	bpos;

	const char	*name;
	t_vector	size;
	t_vector	pos;
	int			max_iter;
	bool		movable;
	bool		mov_lock;
}				t_fractol;

# define XMAX 900		/* horizonal window size		*/
# define YMAX 900 		/* vertical window size		*/

/* EVENTS */
# define KEYPRESS 2
# define MOUSEPRESS 4
# define MOUSERELEASE 5
# define MOUSEMOVE 6
# define DESTROYNOTIFY 17

/* KEY HOOKS */
# define KEY_ESC 53
# define RETURN_KEY 36
# define TAB_KEY 48
# define SPACE_KEY 49

/* Zoom */
# define MINUS_KEY 27
# define PLUS_KEY 24

/* Move */
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

/* MOUSE HOOKS */
# define LEFT_CLICK 1
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5

int			ft_strcmp(const char *s1, const char *s2);
int			checkinit(t_fractol *fractol, char *param, int mod);

void		zoom_in(t_fractol *fractol, t_vector pos);
void		zoom_out(t_fractol *fractol, t_vector pos);
void		draw_win(t_fractol *fractol);

int			draw_julia(t_fractol *fractol, t_vector pos);
int			draw_sierpinski(t_fractol *fractol, t_vector pos);
int			draw_mandelbrot(t_fractol *fractol, t_vector pos);

void		add_mlx_hook(t_fractol *fractol);
int			fractol_exit(void);

#endif
