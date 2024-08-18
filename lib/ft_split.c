/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:22:04 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/08 08:22:06 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ft_count_words(const char *s, char c)
{
	size_t	result;
	size_t	i;

	i = 0;
	result = 0;
	if (!s)
		return (result);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0' && s[i - 1] != c)
				return (result);
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**spliteds;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	spliteds = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (spliteds == 0 || !s)
		return (NULL);
	spliteds[ft_count_words(s, c)] = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			spliteds[j++] = ft_substr_lib(s, start, (i - start));
		}
		if (s[i++] == '\0')
			return (spliteds);
	}
	return (spliteds);
}
