#include "../inc/philo.h"

int	ft_init_mutex(t_inf *inf)
{
	int nbr;

	nbr = -1;
	
	pthread_mutex_init(&inf->lock, NULL);
	pthread_mutex_init(&inf->writer, NULL);
	
	while (nbr++ < inf->nbr_of_philo)
		pthread_mutex_init(&inf->forks[nbr], NULL);
	return (0);
}

int	ft_init_alloc(t_inf *inf)
{
	inf->forks = malloc(sizeof(pthread_mutex_t) * inf->nbr_of_philo);
	if (!inf->forks)
		return(1);
	inf->ths = malloc(sizeof(pthread_t) * inf->nbr_of_philo);
	if (!inf->ths)
	{
		return (1);
	}
	inf->philos = malloc(sizeof(t_philo) * inf->nbr_of_philo);
	if (!inf->philos)
		return (-1);
	return (0);
}
int	ft_init_forks(t_inf *inf)
{
	int i;

	i = 1;
	while (i < inf->nbr_of_philo)
	{
		inf->philos[i].left_fork = &inf->forks[i];
		inf->philos[i].right_fork = &inf->forks[i - 1];
		i++;
	}
	inf->philos[0].left_fork = &inf->forks[0];
	inf->philos[0].right_fork = &inf->forks[inf->nbr_of_philo - 1];
	return (0);
}

int	ft_init_philos(t_inf	*inf)
{
	int nbr;

	nbr = -1;
	ft_init_forks(inf);
	while (++nbr < inf->nbr_of_philo)
	{
		inf->philos[nbr].name = nbr + 1;
		inf->philos[nbr].time_last_eat = ft_actual_time(inf);
		inf->philos[nbr].eating	= 0;
		inf->philos[nbr].sleeping = 0;
		inf->philos[nbr].thinking = 0;
		pthread_mutex_init(&inf->philos[nbr].lock, NULL);
		inf->philos[nbr].inf = inf;
	}
	return (0);	
}

int	ft_init(t_inf *inf,int ac, char **av)
{
	if (ft_init_struct(inf, ac, av) != 0)
		return (1);
	if (ft_init_alloc(inf) != 0)
		return (1);
	if (ft_init_mutex(inf) != 0)
		return (1);
	if (ft_init_philos(inf) != 0)
		return (1);
	return (0);
}

int	ft_init_struct(t_inf *inf, int ac, char **av)
{
	struct timeval	time;

	inf->nbr_of_philo = ft_atoi(av[1]);
	inf->time_to_die = ft_atoi(av[2]);
	inf->time_to_eat = ft_atoi(av[3]);
	inf->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		inf->nbr_meals = ft_atoi(av[5]);
	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	inf->start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	inf->dead = 0;
	inf->finished = 0;
	return (0);
}
