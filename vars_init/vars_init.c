/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:16:25 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 16:43:58 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	saves_xy_len(t_vars *vars)
{
	int		x_len;
	int		y_len;
	char	*lol;
	int		fd;

	fd = open(vars->argv[1], O_RDONLY);
	lol = get_next_line(fd);
	x_len = ft_count_word(lol);
	vars->saves.x_len = x_len;
	y_len = 0;
	while (lol)
	{
		free(lol);
		lol = get_next_line(fd);
		y_len++;
	}
	close(fd);
	vars->saves.y_len = y_len;
}

float	get_initial_scale(t_vars vars)
{
	float	s;
	int		i;
	int		len;

	s = 1;
	len = vars.saves.x_len;
	i = vars.saves.width * 0.2;
	while ((s * len) < i)
		s = s * 1.1;
	return (s);
}

void	saves_init(t_vars *vars)
{
	saves_xy_len(vars);
	vars->saves.color = 0;
	vars->saves.width = 1900;
	vars->saves.height = 1000;
	vars->saves.xx = vars->saves.width * 0.5;
	vars->saves.yy = vars->saves.height * 0.35;
	vars->saves.s = get_initial_scale(*vars);
}

void	vars_init(t_vars *vars, char **argv)
{
	vars->argv = argv;
	saves_init(vars);
	vars->mlx = mlx_init();
	vars->mlx_window = mlx_new_window(vars->mlx, vars->saves.width,
			vars->saves.height, "fdf");
	vars->img.img = mlx_new_image(vars->mlx, vars->saves.width,
			vars->saves.height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_length, &vars->img.endian);
}
