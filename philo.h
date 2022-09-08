#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_init
{
    int dead_flag;
    int num_of_philos;
    int die;
    int eat;
    int sleep;
    int numb_dinners;
}t_init;

typedef struct s_philo
{
    pthread_t p;
    pthread_mutex_t *right;
    pthread_mutex_t *left;
    t_init *init;
    int id;
}t_philo;

void	ft_error(char *str);
void	ft_putstr_fd(char *s, int fd);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);

#endif