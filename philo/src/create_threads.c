#include "../inc/philo.h"

int	ft_create_threads(t_inf *inf)
{
	int	i;

	i = -1;
	pthread_t	thread;
	if (inf->nbr_of_meals > 0)
	{
		if (pthread_create(&thread, NULL, &meal_checks, inf->philos))
			return (-1);
	}
	while (++i < inf->nbr_of_philo)
	{
		if (pthread_create(&inf->ths[i], NULL, &ft_routine, &inf->philos[i]) != 0)
			return (-1);
		usleep(1000);
	}
	i = -1;
	while (++i < inf->nbr_of_philo)
	{
		if (pthread_join(inf->ths[i], NULL))
			return (-1);
	}
	if (pthread_join(thread, NULL))
		return (-1);
	
	return (0);
}
