/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:29:36 by kel-baam          #+#    #+#             */
/*   Updated: 2023/03/18 14:29:39 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	long	time;

	time = (get_time_us() - philo->start_time) / 1000;
	if (is_running(philo))
	{
		pthread_mutex_lock(&(philo->data->print_mutex));
		ft_putnbr((time));
		write(1, " ", 1);
		ft_putnbr(philo->id + 1);
		write(1, " ", 1);
		write(1, action, ft_strlen(action));
		write(1, "\n", 1);
		pthread_mutex_unlock(&(philo->data->print_mutex));
	}
}

t_data	*init(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->num_philo == -1 || data->time_to_eat == -1
		|| data->time_to_sleep == -1 || data->time_to_die == -1)
		return (NULL);
	data->num_of_eating = -1;
	if (ac == 6)
	{
		data->num_of_eating = ft_atoi(av[5]);
		if (data->num_of_eating == -1)
			return (NULL);
	}
	return (data);
}

void	stop_philos(t_philo *philosophers, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_lock(&(philosophers[i].alive));
		philosophers[i].flag = 0;
		pthread_mutex_unlock(&(philosophers[i].alive));
		i++;
	}
}

void	join_and_detach(t_data *data, pthread_t *threads)
{
	int	i;

	if (data->num_philo == 1)
		pthread_detach(threads[0]);
	else
	{
		i = 0;
		while (i < data->num_philo)
		{
			pthread_join(threads[i], NULL);
			i++;
		}
	}
}
