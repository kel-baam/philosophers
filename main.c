/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:46:26 by kel-baam          #+#    #+#             */
/*   Updated: 2023/03/06 14:46:30 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->print_mutex), NULL);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philosophers;
	pthread_t	*threads;

	if (ac == 6 || ac == 5)
	{
		data = init(ac, av);
		if (!data)
			return (1);
		philosophers = malloc(sizeof(t_philo) * data->num_philo);
		data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
		threads = malloc(sizeof(pthread_t) * data->num_philo);
		init_mutex(data);
		if (!creat_threads(philosophers, threads, data))
		{
			supervisor(philosophers, data);
			stop_philos(philosophers, data->num_philo);
			join_and_detach(data, threads);
		}
		free_all(philosophers, data);
	}
	return (0);
}
