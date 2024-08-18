/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:52:21 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 01:13:57 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	find_z_min(t_vars vars)
{
	int	val;
	int	x;
	int	y;

	x = 0;
	val = vars.map[0][0].point.z;
	while (x < vars.saves.x_len)
	{
		y = 0;
		while (y < vars.saves.y_len)
		{
			if (val > vars.map[x][y].point.z)
				val = vars.map[x][y].point.z;
			y++;
		}
		x++;
	}
	return (val);
}

int	find_z_max(t_vars vars)
{
	int	val;
	int	x;
	int	y;

	x = 0;
	val = vars.map[0][0].point.z;
	while (x < vars.saves.x_len)
	{
		y = 0;
		while (y < vars.saves.y_len)
		{
			if (val < vars.map[x][y].point.z)
				val = vars.map[x][y].point.z;
			y++;
		}
		x++;
	}
	return (val);
}

int	chunk_id(int value, int min, int max)
{
	float	chunk_width;
	float	id;

	id = 0;
	if (value < min || value > max)
		return (-1);
	chunk_width = (float)(max - min) / 10;
	if (chunk_width == 0)
		return (id);
	id = (value - min) / chunk_width;
	if (id > 10)
		id = 10;
	return ((int)id);
}

void	color_attribution(t_vars vars, int x, int y)
{
	int	id;
	int	value;

	value = vars.map[x][y].point.z;
	id = chunk_id(value, vars.saves.z_min, vars.saves.z_max);
	if (id == 0)
		vars.map[x][y].point.color = 0xb7bdf8;
	else if (id == 1)
		vars.map[x][y].point.color = 0x8aadf4;
	else if (id == 2)
		vars.map[x][y].point.color = 0x7dc4e4;
	else if (id == 3)
		vars.map[x][y].point.color = 0x91d7e3;
	else if (id == 4)
		vars.map[x][y].point.color = 0x8bd5ca;
	else if (id == 5)
		vars.map[x][y].point.color = 0xa6da95;
	else if (id == 6)
		vars.map[x][y].point.color = 0xeed49f;
	else if (id == 7)
		vars.map[x][y].point.color = 0xf5a97f;
	else if (id == 8)
		vars.map[x][y].point.color = 0xee99a0;
	else
		vars.map[x][y].point.color = 0xed8796;
}
