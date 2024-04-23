/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:00:16 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/12/19 16:57:19 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Converts an array containing a floating point to double type number
double	ft_atod(char *s)
{
	double	i;
	double	fractional;
	double	pow;
	int		operator;

	i = 0;
	fractional = 0;
	operator = 1;
	pow = 1;
	while ((*s > 8 && *s < 14) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			operator = -operator;
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow = pow / 10;
		fractional = fractional + (*s++ - '0') * pow;
	}
	return ((i + fractional) * operator);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (s1[count] == s2[count] && count < n
		&& s1[count] && s2[count])
		count++;
	if (count == n)
		return (0);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
