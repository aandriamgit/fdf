/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:42:26 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/16 16:34:09 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arg_check(char **argv)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (argv[1][i])
		i++;
	if (!(argv[1][i - 1] == 'f' && argv[1][i - 2] == 'd' && argv[1][i
			- 3] == 'f' && argv[1][i - 4] == '.'))
		res = 0;
	else if (!valid_file(argv))
		res = 0;
	else if (!valid_points(argv))
		res = 0;
	return (res);
}

void	map_init(t_vars *vars)
{
	int	x;

	x = 0;
	vars->map = malloc(sizeof(t_map *) * vars->saves.x_len);
	while (x < vars->saves.x_len)
	{
		vars->map[x] = malloc(sizeof(t_map) * vars->saves.y_len);
		x++;
	}
	map_xyz_init(vars);
	color_init(vars);
}

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x <= vars->saves.width)
	{
		y = 0;
		while (y <= vars->saves.height)
		{
			better_pixel_put(vars, x, y, 0x1e1e2e);
			y++;
		}
		x++;
	}
	draw_x(vars);
	draw_y(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_window, vars->img.img, 0, 0);
}

int	key_hooks(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		escape_hook(vars);
	else if (keycode == 119 && vars->saves.yy > 100)
		w_hook(vars);
	else if (keycode == 97 && vars->saves.xx > 100)
		a_hook(vars);
	else if (keycode == 115 && vars->saves.yy < 700)
		s_hook(vars);
	else if (keycode == 100 && vars->saves.xx < 1700)
		d_hook(vars);
	else if (keycode == 65362 && vars->saves.s < 100)
		scale_up_hook(vars);
	else if (keycode == 65364 && vars->saves.s > 2)
		scale_down_hook(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2 && arg_check(argv))
	{
		vars_init(&vars, argv);
		map_init(&vars);
		mlx_key_hook(vars.mlx_window, key_hooks, &vars);
		mlx_hook(vars.mlx_window, 17, 0, close_window, &vars);
		draw_map(&vars);
		mlx_loop(vars.mlx);
	}
	else
		write(2, "Map Error\n", 10);
	return (0);
}
