#include "../inc/philo.h"

void	ft_create_philo(t_info	*info)
{
	int philo;
	int nbr;

	nbr = 0;
	info->philo = (t_philo *)malloc(sizeof(t_philo *) * info->nbr_of_philo);
	while (nbr < info->nbr_of_philo)
	{
		info->philo[nbr].value = nbr + 1;
		info->philo[nbr].fork = true;
		info->philo[nbr].info = info;
		nbr++;
	}
}