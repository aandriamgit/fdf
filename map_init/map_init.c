/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:39 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 17:15:33 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_xyz_init(t_vars *vars)
{
	char	**splited;
	char	*lol;
	int		fd;
	int		x;
	int		y;

	y = 0;
	fd = open(vars->argv[1], O_RDONLY);
	while (y < vars->saves.y_len)
	{
		x = 0;
		lol = get_next_line(fd);
		if (have_color(lol))
			vars->saves.color = 1;
		splited = ft_split(lol, ' ');
		while (x < vars->saves.x_len)
		{
			aeternam_xyz(vars, splited, x, y);
			x++;
		}
		free_up(*vars, &lol, splited);
		y++;
	}
	close(fd);
}

void	color_init(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->saves.color)
		return ;
	else
	{
		x = 0;
		vars->saves.z_min = find_z_min(*vars);
		vars->saves.z_max = find_z_max(*vars);
		while (x < vars->saves.x_len)
		{
			y = 0;
			while (y < vars->saves.y_len)
			{
				color_attribution(*vars, x, y);
				y++;
			}
			x++;
		}
	}
}
