/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:45:16 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/16 10:17:48 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line/get_next_line.h"
# include "./lib/lib.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_map
{
	t_point	point;
}			t_map;

typedef struct s_saves
{
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	int		x_len;
	int		y_len;
	float	s;
	int		xx;
	int		yy;
	int		color;
}			t_saves;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_window;
	t_saves	saves;
	t_data	img;
	t_map	**map;
	char	**argv;
	int		status;
}			t_vars;

int			valid_points(char **argv);
int			find_z_min(t_vars vars);
int			find_z_max(t_vars vars);
void		color_attribution(t_vars vars, int x, int y);
int			ft_count_word(char *str);
void		vars_init(t_vars *vars, char **argv);
void		map_xyz_init(t_vars *vars);
char		*sub_color(char *str);
int			hex_to_int(char *str);
int			have_color(char *lol);
void		aeternam_xyz(t_vars *vars, char **splited, int x, int y);
void		free_up(t_vars vars, char **lol, char **splited);
void		color_init(t_vars *vars);
int			close_window(t_vars *vars);
void		escape_hook(t_vars *vars);
void		better_pixel_put(t_vars *vars, int x, int y, int color);
void		draw_x(t_vars *vars);
void		draw_y(t_vars *vars);
void		bresenham_line_iso(t_vars vars, t_point a, t_point b);
int			color_gradient(int x, int y, t_point a, t_point b);
void		draw_map(t_vars *vars);
void		w_hook(t_vars *vars);
void		s_hook(t_vars *vars);
void		d_hook(t_vars *vars);
void		a_hook(t_vars *vars);
void		scale_up_hook(t_vars *vars);
void		scale_down_hook(t_vars *vars);
void		center_hook(t_vars *vars);
int			valid_file(char **argv);

#endif
