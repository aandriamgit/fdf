/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 07:52:45 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 17:41:19 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham_y(t_vars vars, t_point a, t_point b)
{
	float	p;
	float	y;
	float	x;

	y = a.y;
	x = a.x;
	y++;
	p = (2 * (abs(b.x - a.x))) - (abs(b.y - b.y));
	while (y != b.y)
	{
		better_pixel_put(&vars, ((x) + vars.saves.xx), ((y) + vars.saves.yy),
			color_gradient(x, y, a, b));
		if (a.y > b.y)
			y--;
		else
			y++;
		if (p < 0)
			p = p + (2 * (abs(b.x - a.x)));
		else
		{
			p = p + (2 * (abs(b.x - a.x))) - (2 * (abs(b.y - a.y)));
			x++;
		}
	}
}

void	bresenham_x(t_vars vars, t_point a, t_point b)
{
	float	p;
	float	y;
	float	x;

	y = a.y;
	x = a.x;
	x++;
	p = (2 * (abs(b.y - a.y))) - (abs(b.x - b.x));
	while (x <= b.x)
	{
		better_pixel_put(&vars, ((x) + vars.saves.xx), ((y) + vars.saves.yy),
			color_gradient(x, y, a, b));
		x++;
		if (p < 0)
			p = p + (2 * (abs(b.y - a.y)));
		else
		{
			p = p + (2 * (abs(b.y - a.y))) - (2 * (abs(b.x - a.x)));
			if (a.y > b.y)
				y--;
			else
				y++;
		}
	}
}

void	bresenham_line_iso(t_vars vars, t_point a, t_point b)
{
	int	dx;
	int	dy;

	dx = abs(b.x - a.x);
	dy = abs(b.y - a.y);
	if (dx < dy)
		bresenham_y(vars, a, b);
	else
		bresenham_x(vars, a, b);
}
