#include "../inc/philo.h"

void	ft_create_multiple_mutex(t_info *info)
{
	int nbr;

	nbr = 0;
	
	info->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->nbr_of_philo);
	while (nbr < info->nbr_of_philo)
	{
		pthread_mutex_init(&info->mutex[nbr], NULL);
		nbr++;
	}
}