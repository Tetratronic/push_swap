/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:57:45 by abenkaro          #+#    #+#             */
/*   Updated: 2025/01/26 22:14:27 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

long	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]))
	{
		if ((result > (long)INT_MAX / 10)
			|| (result == INT_MAX / 10 && (str[i] - 48) > INT_MAX % 10 + 1))
			return ((long)INT_MAX + 1);
		result = (result * 10) + (str[i] - 48);
		if (result == (long)2147483648 && sign > 0)
			return ((long)INT_MAX + 1);
		i++;
	}
	return ((long)result * sign);
}
