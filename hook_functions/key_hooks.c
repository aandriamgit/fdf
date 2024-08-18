/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:00:18 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/16 14:10:47 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	w_hook(t_vars *vars)
{
	vars->saves.yy *= 0.9;
	draw_map(vars);
}

void	s_hook(t_vars *vars)
{
	vars->saves.yy *= 1.1;
	draw_map(vars);
}

void	d_hook(t_vars *vars)
{
	vars->saves.xx *= 1.1;
	draw_map(vars);
}

void	a_hook(t_vars *vars)
{
	vars->saves.xx *= 0.9;
	draw_map(vars);
}

void	escape_hook(t_vars *vars)
{
	int	x;

	x = -1;
	if (vars->img.img)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->mlx_window);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		while (++x < vars->saves.x_len)
			free(vars->map[x]);
		free(vars->map);
		exit(0);
	}
}
