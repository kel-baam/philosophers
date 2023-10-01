/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:30:30 by kel-baam          #+#    #+#             */
/*   Updated: 2023/03/18 14:30:32 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define MSG_ERR "ERROR\n"

int					print_error(void);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
long				get_time_ms(void);

typedef struct t_data
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_philo;
	int				num_of_eating;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;

}					t_data;
typedef struct t_philo
{
	int				id;
	struct t_data	*data;
	long			last_meal_time;
	long			start_time;
	int				meal_count;
	pthread_mutex_t	var_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	alive;
	int				flag;
}					t_philo;
void				print_struct(t_data data);
void				print_action(t_philo *philo, char *action);
void				take_forks(t_philo *philo);
void				put_forks(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
long				get_time_us(void);
void				my_sleep(int time_to_sleep);
int					ft_putnbr(int nb);
void				*philosopher(void *arg);
void				supervisor(t_philo *philosophers, t_data *data);
t_data				*init(int ac, char **av);
void				*ft_calloc(size_t count, size_t size);
void				stop_philos(t_philo *philosophers,
						int num_philo);
void				free_all(t_philo *philosophers, t_data *data);
void				join_and_detach(t_data *data, pthread_t *threads);
int					is_running(t_philo *philo);
int					creat_threads(t_philo *philosophers, pthread_t *thread,
						t_data *data);
void				supervisor(t_philo *philosophers, t_data *data);
#endif
