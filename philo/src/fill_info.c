#include "../inc/philo.h"

void	ft_fill_info(int ac, char **av, t_info *info)
{
	info->nbr_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->nbr_times_eat = ft_atoi(av[5]);
	else
		info->nbr_times_eat = -1;
}
