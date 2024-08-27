/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:17:34 by ouboukou          #+#    #+#             */
/*   Updated: 2024/06/30 23:43:55 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*space_and_sign(const char *str, int *sign)
{
	while (*str && ft_isspace(*str) == 0)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -(*sign);
		str++;
	}
	return ((char *)str);
}

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	result;
	char		*new_str;

	i = 0;
	sign = 1;
	result = 0;
	new_str = space_and_sign(str, &sign);
	while (new_str[i] && ft_isdigit(new_str[i]) == 0)
	{
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && new_str[i]
				- '0' > LONG_MAX % 10))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (new_str[i] - '0');
		i++;
	}
	return (result * sign);
}
