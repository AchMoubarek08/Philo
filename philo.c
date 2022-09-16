/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:42:22 by amoubare          #+#    #+#             */
/*   Updated: 2022/09/16 02:59:49 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philos)
	{
		if (get_time_now() - philo[i].last_dinner > philo->init->die && philo[i].last_dinner != 0)
		{
			print(&philo[i], philo->init->start_time, "died");
			i = 0;
			while (i < philo->num_of_philos)
			{
				philo[i].dead_flag = 1;
				i++;
			}
			return (1);
		}
	}
	return (0);
}

int	check_dinners(t_philo *philo)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < philo->num_of_philos)
	{
		printf("%d\n", total);
		total += philo[i].philo_eat;
		if (total == philo->num_of_philos * philo->init->numb_dinners)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_init	*init;
	t_philo	*philo;

	init = malloc(sizeof(t_init));
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (argc == 5 || argc == 6)
		initialize(argc, argv, init);
	else
		ft_error("Wrong number of arguments\n");
	init_philos(philo, init);
	go_threads(philo, init);
	while (check_death(philo) == 0)
		;
	return (0);
}
