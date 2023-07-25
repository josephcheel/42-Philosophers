#include "../inc/philo.h"

void ft_delete(t_inf *inf)
{
	int i;

	i = -1;
	pthread_mutex_destroy(&inf->lock);
	pthread_mutex_destroy(&inf->writer);
	while (i++ < inf->nbr_of_philo)
	{
		pthread_mutex_destroy(&inf->forks[i]);
	}
	if (inf->forks)
		free(inf->forks);
	if (inf->philos)
		free(inf->philos);
	// if (inf)
	// 	free(inf);

}