/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:01:31 by amoubare          #+#    #+#             */
/*   Updated: 2022/09/17 01:49:35 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_init
{
	pthread_mutex_t	print;
	pthread_mutex_t	write_lock;
	int				num_of_philos;
	int				die;
	int				eat;
	int				sleep;
	int				numb_dinners;
	long int		start_time;
}t_init;

typedef struct s_philo
{
	int				num_of_philos;
	pthread_t		p;
	int				dead_flag;
	pthread_mutex_t	left_f;
	pthread_mutex_t	*right_f;
	t_init			*init;
	long int		last_dinner;
	int				ate;
	int				finish;
	int				id;
}t_philo;

void		ft_error(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			init_philos(t_philo *philo, t_init *init);
void		initialize(int argc, char **argv, t_init *init);
int			go_threads(t_philo *philo, t_init *init);
long int	get_time_now(void);
void		sleeping(unsigned long long timetosleep);
int			check_death(t_philo *philo);
void		print(t_philo *philo, long int time, char *str);
#endif