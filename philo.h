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
    pthread_mutex_t print;
    int dead_flag;
    int num_of_philos;
    int die;
    int eat;
    int sleep;
    long int start_time;
    int numb_dinners;
}t_init;

typedef struct s_philo
{
    int num_of_philos;
    pthread_t p;
    pthread_mutex_t left_f;
    pthread_mutex_t *right_f;
    t_init *init;
    long int last_dinner;
    int id;
}t_philo;

void	    ft_error(char *str);
void	    ft_putstr_fd(char *s, int fd);
int         ft_atoi(const char *str);
int         ft_isdigit(int c);
int         go_threads(t_philo *philo, t_init *init);
int         init_philos(t_philo *philo, t_init *init);
void        initialize(int argc, char **argv, t_init *init);
long int    get_time_now(void);
void	    sleeping(unsigned long long timetosleep);

#endif