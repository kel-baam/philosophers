/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:40:55 by kel-baam          #+#    #+#             */
/*   Updated: 2023/03/18 16:40:59 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	take_forks(t_philo *philo)
{
	t_data	*data;
	int		right_fork;
	int		left_fork;

	data = philo->data;
	right_fork = (philo->id + 1) % data->num_philo;
	left_fork = philo->id;
	if (is_running(philo))
	{
		pthread_mutex_lock(&(data->forks[left_fork]));
		print_action(philo, "has taken a fork");
	}
	if (is_running(philo))
	{
		pthread_mutex_lock(&(data->forks[right_fork]));
		print_action(philo, "has taken a fork");
	}
}

void	put_forks(t_philo *philo)
{
	t_data	*data;
	int		right_fork;
	int		left_fork;

	data = philo->data;
	right_fork = (philo->id + 1) % data->num_philo;
	left_fork = philo->id;
	pthread_mutex_unlock(&(data->forks[right_fork]));
	pthread_mutex_unlock(&(data->forks[left_fork]));
}

void	ft_eat(t_philo *philo)
{
	if (is_running(philo))
	{
		print_action(philo, "is eating");
		my_sleep(philo->data->time_to_eat);
		pthread_mutex_lock(&(philo->var_mutex));
		philo->meal_count++;
		philo->last_meal_time = get_time_us();
		pthread_mutex_unlock(&(philo->var_mutex));
	}
}

void	ft_sleep(t_philo *philo)
{
	if (is_running(philo))
	{
		print_action(philo, "is sleeping");
		my_sleep(philo->data->time_to_sleep);
	}
}

void	ft_think(t_philo *philo)
{
	if (is_running(philo))
		print_action(philo, "is thinking");
}
