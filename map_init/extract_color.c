/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:22:20 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/15 00:26:53 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_isblank(char c)
{
	if (c == 0)
		return (0);
	if (c <= 32)
		return (1);
	return (0);
}

int	ft_isvalid(char c, int base)
{
	char	*digits;
	char	*digits2;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int	ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	hex_to_int(char *str)
{
	int	result;
	int	sign;

	result = 0;
	if (!str)
		return (0);
	while (ft_isblank(*str))
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isvalid(*str, 16))
		result = result * 16 + ft_value_of(*str++);
	return (result * sign);
}

char	*sub_color(char *str)
{
	while (*str != '\0')
	{
		if (*str == 'x')
			return (++str);
		str++;
	}
	return (NULL);
}
