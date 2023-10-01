/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:24:55 by kel-baam          #+#    #+#             */
/*   Updated: 2023/03/18 14:25:01 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	my_sleep(int time_to_sleep)
{
	long	end;

	end = get_time_us() + time_to_sleep * 1000;
	usleep(time_to_sleep * 1000 - 14000);
	while (get_time_us() <= end)
	{
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	get_time_us(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	print_error(void)
{
	write(STDERR_FILENO, MSG_ERR, ft_strlen(MSG_ERR));
	return (-1);
}

void	free_all(t_philo *philosophers, t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(data->print_mutex));
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&(philosophers[i].var_mutex));
		pthread_mutex_destroy(&(philosophers[i].eat_mutex));
		pthread_mutex_destroy(&(philosophers[i].alive));
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	free(data->forks);
	free(data);
	free(philosophers);
}
