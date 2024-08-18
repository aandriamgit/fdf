/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:55:52 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/08 08:55:54 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

size_t	ft_strlen_lib(const char *s)
{
	size_t	numb_bytes;

	numb_bytes = 0;
	while (s[numb_bytes] != '\0')
	{
		numb_bytes++;
	}
	return (numb_bytes);
}
