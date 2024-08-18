/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:05:58 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/17 11:58:57 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*mini_join_them(char *newbie, int i, int j)
{
	newbie[i + j] = '\0';
	return (newbie);
}

char	*join_them(char *new_buff, char *temp)
{
	char	*newbie;
	int		i;
	int		j;
	int		len;

	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(new_buff) + ft_strlen(temp);
	newbie = malloc(sizeof(char) * (len + 1));
	if (newbie == 0)
		return (NULL);
	while (new_buff[i] != '\0')
	{
		newbie[i] = new_buff[i];
		i++;
	}
	free(new_buff);
	while (temp[j] != '\0')
	{
		newbie[i + j] = temp[j];
		j++;
	}
	return (mini_join_them(newbie, i, j));
}

size_t	ft_strlen(const char *s)
{
	size_t	numb_bytes;

	numb_bytes = 0;
	while (s[numb_bytes] != '\0')
	{
		numb_bytes++;
	}
	return (numb_bytes);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start == ft_strlen(s))
		return (NULL);
	new = malloc((sizeof(char)) * (len + 1));
	if (new == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			new[j] = s[i];
			j++;
		}
		i++;
	}
	return (new[j] = '\0', new);
}

char	have_nl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return ('n');
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return ('y');
		i++;
	}
	return ('n');
}
