/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:21:01 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/16 14:15:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	scale_up_hook(t_vars *vars)
{
	vars->saves.s *= 1.1;
	draw_map(vars);
}

void	scale_down_hook(t_vars *vars)
{
	vars->saves.s *= 0.9;
	draw_map(vars);
}
