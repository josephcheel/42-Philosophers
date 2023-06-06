#include "../inc/philo.h"

void	*ft_do_smth()
{
	printf("HOLA");
	return (NULL);
}

int	ft_create_threads(t_info *info)
{
	int				i;
	pthread_t		*thread;
	pthread_mutex_t	mutex;


	i = -1;
	thread = (pthread_t *)malloc(sizeof(pthread_t *) * info->nbr_of_philo);
	if (!thread)
		return (-1);
	pthread_mutex_init(&mutex, NULL);
	while (i++ < info->nbr_of_philo)
		if (pthread_create(&thread[i], NULL, &ft_do_smth, NULL) != 0)
			return (-1);
	i = -1;
	while (i++ < info->nbr_of_philo)
		if (pthread_join(thread[i], NULL) != 0)
			return (-1);
	pthread_mutex_destroy(&mutex);
	return (0);
}
