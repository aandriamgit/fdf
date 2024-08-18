/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_xyz_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:35:55 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 06:08:49 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	have_color(char *lol)
{
	int	i;

	i = 0;
	while (lol[i] != '\0')
	{
		if (lol[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	extract_color(char *splited)
{
	if (have_color(splited))
		return (hex_to_int(sub_color(splited)));
	else
		return (0xcdd6f4);
}

void	aeternam_xyz(t_vars *vars, char **splited, int x, int y)
{
	vars->map[x][y].point.x = x;
	vars->map[x][y].point.y = y;
	vars->map[x][y].point.z = (ft_atoi(splited[x]));
	vars->map[x][y].point.color = extract_color(splited[x]);
}

void	free_up(t_vars vars, char **lol, char **splited)
{
	int	i;

	i = 0;
	while (i < vars.saves.x_len)
	{
		free(splited[i]);
		i++;
	}
	free(*lol);
	free(splited);
}
