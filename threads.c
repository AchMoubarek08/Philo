/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:42:38 by amoubare          #+#    #+#             */
/*   Updated: 2022/09/17 05:54:35 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	print(t_philo *philo, long int time, char *str)
{
	long int	time_now;

	time_now = get_time_now() - philo->init->start_time;
	pthread_mutex_lock(&philo->init->print);
	printf("%ld %d %s\n", time_now, philo->id, str);
	pthread_mutex_unlock(&philo->init->print);
}
void	sleeping(unsigned long long timetosleep)
{
	unsigned long long	time;

	time = get_time_now();
	while (get_time_now() - time < timetosleep)
		usleep(timetosleep / 10);
}

long int	get_time_now(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_error("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	*routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	while (philo->dead_flag < 1)
	{
		pthread_mutex_lock(&(philo->left_f));
		print(philo, philo->init->start_time, "has taken a fork");
		pthread_mutex_lock((philo->right_f));
		print(philo, philo->init->start_time, "has taken a fork");
		print(philo, philo->init->start_time, "is eating");
		philo->last_dinner = get_time_now();
		sleeping(philo->init->eat);
		philo->ate++;
		if(philo->finish == 1)
			break;
		pthread_mutex_unlock(&(philo->left_f));
		pthread_mutex_unlock((philo->right_f));
		print(philo, philo->init->start_time, "is sleeping");
		sleeping(philo->init->sleep);
		print(philo, philo->init->start_time, "is thinking");
	}
	return (NULL);
}

int	go_threads(t_philo *philo, t_init *init)
{
	int	i;

	i = 0;
	while (i < init->num_of_philos)
	{
		pthread_create(&philo[i].p, NULL, routine, &philo[i]);
		pthread_detach(philo[i].p);
		i++;
		usleep(40);
	}
	return (0);
}
