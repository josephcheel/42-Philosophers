#include "../inc/philo.h"

void	*ft_create_philo(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;

	// printf("%d\n", info->nbr_of_philo);
	// printf("%d\n", info->time_to_die);
	// printf("%d\n", info->time_to_eat);
	// printf("%d\n", info->time_to_sleep);
	// pthread_mutex_lock(&info->mutex);
	info->time_to_die += 1;
	printf("time to dieaaa %d\n", info->time_to_die);
	// printf("%d\n", info->nbr_of_philo);
	// pthread_mutex_unlock(&info->mutex);
	return (NULL);
}

int	ft_create_threads(t_info *info)
{
	int				i;
	pthread_t		*thread;

	i = 0;
	// printf("NBR OF PHILO: %d\n", table->info->nbr_of_philo);
	thread = (pthread_t *)malloc(sizeof(pthread_t *) * info->nbr_of_philo);
	if (!thread)
		return (-1);
	pthread_mutex_init(&info->mutex[i], NULL);
	while (i < info->nbr_of_philo)
	{
		if (pthread_create(&thread[i], NULL, &ft_create_philo, (void *)&info->philo[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (thread[i])//(i < info->nbr_of_philo)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (-1);
		i++;
	}
	free(thread);
	pthread_mutex_destroy(&info->mutex[i]);
	return (0);
}
