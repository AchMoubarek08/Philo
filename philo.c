#include "philo.h"

pthread_mutex_t mutex;

void    *func()
{
    pthread_mutex_lock(&mutex);
    printf("ok\n");
    printf("okok\n");
    printf("njdk\n");
    sleep(2);
    printf("4\n");
    printf("5\n");
    printf("6\n");
    pthread_mutex_unlock(&mutex);
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

int main(int argc, char **argv)
{
    t_init init;
    if(argc == 5 || argc == 6)
        initialize(argc, argv, &init);
    else
        ft_error("Wrong number of arguments\n");
    // pthread_t a, b;
    // pthread_mutex_init(&mutex, NULL);
    // pthread_create(&a, NULL, &func, NULL);
    // pthread_create(&b, NULL, &func, NULL);
    // pthread_join(a, NULL);
    // pthread_join(b, NULL);
    // pthread_mutex_destroy(&mutex);
    return(0);
}