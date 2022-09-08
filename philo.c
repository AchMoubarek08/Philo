#include "philo.h"

void    *func(void *var)
{
    t_philo *philo = (t_philo *)var;
    pthread_mutex_lock(philo->right);
    printf("%d\n", philo->id);
    pthread_mutex_unlock(philo->right);
    return(NULL);
}

void    initialize(int argc, char **argv, t_init *init)
{
    init->num_of_philos = ft_atoi(argv[1]);
    init->die = ft_atoi(argv[2]);
    init->eat = ft_atoi(argv[3]);
    init->sleep = ft_atoi(argv[4]);
    if(argc == 6)
        init->numb_dinners = ft_atoi(argv[5]);
    
}

float get_time_now(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return(tv.tv_usec * 0.001);
}

int init_philos(t_philo *philo, t_init *init)
{
    int i = 0;
    philo = malloc(sizeof(t_philo) * init->num_of_philos);
    pthread_mutex_t *forks = malloc(sizeof(pthread_mutex_t) * init->num_of_philos);
    while(i < init->num_of_philos)
    {
        philo[i].left = pthread_mutex_init(&fork[i], NULL);
        philo[i].id = i + 1;
    }
}

int go_threads(t_philo *philo, t_init *init)
{
    int i = 0;
    while(i < init->num_of_philos)
    {
        pthread_create(&philo[i].p, NULL, func, (void *)&philo);
        pthread_join(philo[i].p, NULL);
        i++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    t_init init;
    t_philo *philo;
    if(argc == 5 || argc == 6)
        initialize(argc, argv, &init);
    else
        ft_error("Wrong number of arguments\n");
    init_philos(philo, &init);
    go_threads(philo, &init);
    return(0);
}