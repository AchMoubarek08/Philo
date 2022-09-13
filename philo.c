#include "philo.h"
void print(t_philo *philo, long int time ,char *str)
{
    long int time_now  = get_time_now() - philo->init->start_time;
    pthread_mutex_lock(&philo->init->print);
    printf("%ld %d %s\n", time_now, philo->id, str);
    pthread_mutex_unlock(&philo->init->print);
}
void    *func(void *var)
{
    while(1)
    {
        t_philo *philo = (t_philo *)var;
        pthread_mutex_lock(&(philo->left_f));
        print(philo, philo->init->start_time, "has taken a fork");
        pthread_mutex_lock((philo->right_f));
        print(philo, philo->init->start_time, "has taken a fork");
        print(philo, philo->init->start_time, "is eating");
        sleeping(philo->init->eat);
        philo->last_dinner = get_time_now();
        pthread_mutex_unlock(&(philo->left_f));
        pthread_mutex_unlock((philo->right_f));
        print(philo, philo->init->start_time, "is sleeping");
        sleeping(philo->init->sleep);
        print(philo, philo->init->start_time, "is thinking");
    }
    return(NULL);
}
void	sleeping(unsigned long long timetosleep)
{
	unsigned long long	time;

	time = get_time_now();
	while (get_time_now() - time < timetosleep)
		usleep(timetosleep / 10);
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
        philo[i].id = i + 1;
        if (i == init->num_of_philos - 1)
            philo[i].right_f = &philo[0].left_f;
        else
            philo[i].right_f = &philo[i + 1].left_f;
        i++;
    }

    return(0);
}

int go_threads(t_philo *philo, t_init *init)
{
    int i = 0;
    while(i < init->num_of_philos)
    {
        pthread_create(&philo[i].p, NULL, func, &philo[i]);
        usleep(100);
        // pthread_detach(philo[i].p);
        i+=1;
    }
    // i = 1;
    // while(i < init->num_of_philos)
    // {
    //     pthread_create(&philo[i].p, NULL, func, &philo[i]);
    //     // pthread_detach(philo[i].p);
    //     i += 2;
    // }
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