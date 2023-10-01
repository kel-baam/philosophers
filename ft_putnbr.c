/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:54:50 by kel-baam          #+#    #+#             */
/*   Updated: 2022/11/11 00:18:08 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_putnbr(int nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 0 && nb <= 9)
	{
		c = nb + 48;
		count += write(1, &c, 1);
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}
