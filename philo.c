#include "philo.h"
void print(t_philo *philo, char *str)
{
    printf("%d %s\n", philo->id, str);
}
void    *func(void *var)
{
    t_philo *philo = (t_philo *)var;
    pthread_mutex_lock(&(philo->left_f));
    pthread_mutex_lock((philo->right_f));
    pthread_mutex_lock(&(philo->init->print));
    print(philo, "has taken a fork");
    pthread_mutex_unlock(&(philo->init->print));
    pthread_mutex_lock(&(philo->init->print));
    print(philo, "has taken a fork");
    pthread_mutex_unlock(&(philo->init->print));
    pthread_mutex_lock(&(philo->init->print));
    print(philo, "is eating");
    pthread_mutex_unlock(&(philo->init->print));
    pthread_mutex_unlock(&(philo->left_f));
    pthread_mutex_unlock((philo->right_f));
    return(NULL);
}

void    initialize(int argc, char **argv, t_init *init)
{
    pthread_mutex_init(&init->print, NULL);
    init->num_of_philos = ft_atoi(argv[1]);
    init->die = ft_atoi(argv[2]);
    init->eat = ft_atoi(argv[3]);
    init->sleep = ft_atoi(argv[4]);
    if(argc == 6)
        init->numb_dinners = ft_atoi(argv[5]);
}

long int get_time_now(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_error("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int init_philos(t_philo *philo, t_init *init)
{
    int i = 0;
    // printf("%d\n", init->num_of_philos);
    while(i < init->num_of_philos)
    {
        philo[i].num_of_philos = init->num_of_philos;
        pthread_mutex_init(&philo[i].left_f, NULL);
        philo[i].init = init;
        philo[i].init->start_time = get_time_now();
        printf("%ld\n", philo[i].init->start_time);
        philo[i].id = i + 1;
        i++;
    }

    return(0);
}

int go_threads(t_philo *philo, t_init *init)
{
    int i = 0;
    while(i < init->num_of_philos)
    {
        if (i == init->num_of_philos - 1)
            philo[i].right_f = &philo[0].left_f;
        else
            philo[i].right_f = &philo[i + 1].left_f;
        pthread_create(&philo[i].p, NULL, func, &philo[i]);
        i++;
    }
    i = 0;
    while(i < init->num_of_philos)
    {
        pthread_join(philo[i].p, NULL);
        i++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    t_init *init = malloc(sizeof(init));
    t_philo *philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
    if(argc == 5 || argc == 6)
        initialize(argc, argv, init);
    else
        ft_error("Wrong number of arguments\n");
    init_philos(philo, init);
    go_threads(philo, init);
    return(0);
}