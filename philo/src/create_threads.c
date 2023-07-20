#include "../inc/philo.h"

void	*ft_routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;

	printf("HOLA %d\n", info->philo[1].name);
	return (NULL);
	printf("%d", info->nbr_times_eat);
	
}

int	ft_create_threads(t_info *info)
{
	int				i;
	// pthread_t		*thread;

	i = 0;

	// pthread_mutex_init(&info->mutex[i], NULL);
	while (i < info->nbr_of_philo)
	{
		info->philo[i].th = (pthread_t )malloc(sizeof(pthread_t *) * info->nbr_of_philo);
		if (!info->philo[i].th)
			return (-1);
		// info->philo[i].name = i + 1;
		if (pthread_create(&info->philo[i].th, NULL, &ft_routine, (void *)&info) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (info->philo[i].th)
	{
		if (pthread_join(info->philo[i].th, NULL) != 0)
			return (-1);
		i++;
	}
	// free(thread);
	pthread_mutex_destroy(&info->mutex[i]);
	return (0);
}
