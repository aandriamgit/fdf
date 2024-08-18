/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 06:51:22 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 17:38:37 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(t_point *lol, float s)
{
	float	x;
	float	y;
	float	z;

	z = lol->z * s;
	y = lol->y * s;
	x = lol->x * s;
	lol->x = (x - y) * 707 / 1000;
	lol->y = (x + y) * 408 / 1000 - z * 816 / 1000;
}

void	draw_line(t_vars *vars, t_point one, t_point two)
{
	t_point	a;
	t_point	b;

	if (two.x < one.x)
	{
		a = two;
		b = one;
	}
	else
	{
		a = one;
		b = two;
	}
	bresenham_line_iso(*vars, a, b);
}

void	better_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < vars->saves.width && y < vars->saves.height)
	{
		dst = vars->img.addr + (y * vars->img.line_length + x * (vars->img.bpp
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_x(t_vars *vars)
{
	int		x;
	int		y;
	t_point	a;
	t_point	b;

	y = 0;
	while (y < vars->saves.y_len)
	{
		x = 1;
		while (x < vars->saves.x_len)
		{
			a = vars->map[x][y].point;
			b = vars->map[x - 1][y].point;
			isometric(&a, vars->saves.s);
			isometric(&b, vars->saves.s);
			draw_line(vars, a, b);
			x++;
		}
		y++;
	}
}

void	draw_y(t_vars *vars)
{
	int		x;
	int		y;
	t_point	a;
	t_point	b;

	x = 0;
	while (x < vars->saves.x_len)
	{
		y = 1;
		while (y < vars->saves.y_len)
		{
			a = vars->map[x][y].point;
			b = vars->map[x][y - 1].point;
			isometric(&a, vars->saves.s);
			isometric(&b, vars->saves.s);
			draw_line(vars, a, b);
			y++;
		}
		x++;
	}
}
