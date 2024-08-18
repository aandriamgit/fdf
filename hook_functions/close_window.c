/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 01:49:46 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 01:55:22 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_window(t_vars *vars)
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
	return (0);
}
