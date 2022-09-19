/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:42:22 by amoubare          #+#    #+#             */
/*   Updated: 2022/09/19 08:52:16 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int			i;

	i = 0;
	while (i < philo->num_of_philos)
	{
		if (get_time_now() - philo[i].last_dinner > philo->init->die
			&& philo->last_dinner != -1)
		{
			print(&philo[i], "died");
			i = 0;
			while (i < philo->num_of_philos)
			{
				philo[i].dead_flag = 1;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_dinners(t_philo *philo)
{
	int	i;
	int	meals;

	meals = philo->init->numb_dinners;
	i = 0;
	while (i < philo->init->num_of_philos)
	{
		if (philo[i].ate != meals)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->init->num_of_philos)
	{
		philo[i].finish = 1;
		i++;
	}
	return (1);
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
	while (check_death(philo) == 0 && check_dinners(philo) == 0)
		;
	return (0);
}
