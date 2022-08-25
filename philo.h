#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_init
{
    int num_of_philos;
    int die;
    int eat;
    int sleep;
    int numb_dinners;
}t_init;

void	ft_error(char *str);
void	ft_putstr_fd(char *s, int fd);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);


#endif