/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:42:16 by amoubare          #+#    #+#             */
/*   Updated: 2022/09/16 02:44:51 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(int argc, char **argv, t_init *init)
{
	pthread_mutex_init(&init->print, NULL);
	init->num_of_philos = ft_atoi(argv[1]);
	init->die = ft_atoi(argv[2]);
	init->eat = ft_atoi(argv[3]);
	init->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		init->numb_dinners = ft_atoi(argv[5]);
}

int	init_philos(t_philo *philo, t_init *init)
{
	int	i;

	i = 0;
	while (i < init->num_of_philos)
	{
		philo[i].philo_eat = 0;
		philo[i].num_of_philos = init->num_of_philos;
		philo[i].dead_flag = 0;
		pthread_mutex_init(&philo[i].left_f, NULL);
		philo[i].init = init;
		philo[i].init->start_time = get_time_now();
		philo[i].id = i + 1;
		if (i == init->num_of_philos - 1)
			philo[i].right_f = &philo[0].left_f;
		else
			philo[i].right_f = &philo[i + 1].left_f;
		i++;
	}
	return (0);
}
