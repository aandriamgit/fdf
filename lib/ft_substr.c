/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:25:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/08 08:25:37 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr_lib(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (start > ft_strlen_lib(s))
		len = 0;
	if (len > ft_strlen_lib(s))
		len = ft_strlen_lib(s);
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
	new[j] = '\0';
	return (new);
}
