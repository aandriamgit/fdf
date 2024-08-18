/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:20:33 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/16 16:15:32 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_count_word(char *str)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			while (str[i] && (str[i] == ' ' || str[i] <= 13))
				i++;
			if (str[i])
				wc++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				i++;
		}
	}
	return (wc);
}

int	is_hidden_file(char *lol)
{
	int	i;

	i = 0;
	while (lol[i])
		i++;
	i--;
	while (lol[i] && lol[i] != '.')
		i--;
	i--;
	if (i == 0 && lol[i] == '.')
		return (1);
	if (lol[i] == '/')
		return (1);
	while (lol[i] && lol[i] != '/')
	{
		if (lol[i] == '.')
			return (1);
		i--;
	}
	return (0);
}

int	valid_file(char **argv)
{
	int		fd;
	char	*lol;

	if (is_hidden_file(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	lol = get_next_line(fd);
	if (!lol)
		return (0);
	while (lol)
	{
		free(lol);
		lol = get_next_line(fd);
		close(fd);
	}
	close(fd);
	return (1);
}

int	valid_points(char **argv)
{
	int		fd;
	int		x_len;
	char	*lol;

	fd = open(argv[1], O_RDONLY);
	lol = get_next_line(fd);
	x_len = ft_count_word(lol);
	while (lol)
	{
		if (ft_count_word(lol) != x_len)
		{
			while (lol)
			{
				free(lol);
				lol = get_next_line(fd);
			}
			close(fd);
			return (0);
		}
		free(lol);
		lol = get_next_line(fd);
	}
	close(fd);
	return (1);
}
