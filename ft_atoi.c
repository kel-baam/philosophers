/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:47:32 by kel-baam          #+#    #+#             */
/*   Updated: 2022/10/24 17:09:09 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	convert_to_int(const char *str)
{
	long long	result;
	int			i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
			return (print_error());
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;
	int			len;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		return (print_error());
	}
	else if (str[i] == '+')
		i++;
	len = ft_strlen(str + i);
	if (!len || len > 10)
		return (print_error());
	res = convert_to_int(str + i) * sign;
	if (res > INT32_MAX || res < INT32_MIN)
		return (print_error());
	return (res);
}
