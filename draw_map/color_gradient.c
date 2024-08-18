/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:26:34 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 08:44:23 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	fraction_prim(t_point a, t_point b, int x, int y)
{
	int		dx;
	int		dy;
	float	fraction;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (a.x != b.x)
	{
		if (abs(dx) > abs(dy))
			fraction = (float)(x - a.x) / (b.x - a.x);
		else
			fraction = (float)(y - a.y) / (b.y - a.y);
	}
	return (fraction);
}

int	operator_red(t_point a, t_point b, int x, int y)
{
	int		value;
	int		r_one;
	int		r_two;
	float	fraction;

	r_one = (a.color >> 16) & 0xFF;
	r_two = (b.color >> 16) & 0xFF;
	fraction = fraction_prim(a, b, x, y);
	value = r_one + (r_two - r_one) * fraction;
	return (value);
}

int	operator_green(t_point a, t_point b, int x, int y)
{
	int		value;
	int		r_one;
	int		r_two;
	float	fraction;

	r_one = (a.color >> 8) & 0xFF;
	r_two = (b.color >> 8) & 0xFF;
	fraction = fraction_prim(a, b, x, y);
	value = r_one + (r_two - r_one) * fraction;
	return (value);
}

int	operator_blue(t_point a, t_point b, int x, int y)
{
	int		value;
	int		r_one;
	int		r_two;
	float	fraction;

	r_one = a.color & 0xFF;
	r_two = b.color & 0xFF;
	fraction = fraction_prim(a, b, x, y);
	value = r_one + (r_two - r_one) * fraction;
	return (value);
}

int	color_gradient(int x, int y, t_point a, t_point b)
{
	int	red;
	int	green;
	int	blue;

	red = operator_red(a, b, x, y);
	green = operator_green(a, b, x, y);
	blue = operator_blue(a, b, x, y);
	return (red << 16 | green << 8 | blue);
}
