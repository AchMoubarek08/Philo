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
    int num_of_philos;
    int die;
    int eat;
    int sleep;
    int numb_dinners;
    long int start_time;
}t_init;

typedef struct s_philo
{
    int num_of_philos;
    pthread_t p;
    int dead_flag;
    pthread_mutex_t left_f;
    pthread_mutex_t *right_f;
    t_init *init;
    long int last_dinner;
    unsigned int philo_eat;
    int finish;
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
int         check_death(t_philo *philo);
#endif