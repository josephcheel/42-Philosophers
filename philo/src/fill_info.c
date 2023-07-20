#include "../inc/philo.h"

int	ft_fill_info(int ac, char **av, t_info *info)
{
	struct timeval	time;

	info->nbr_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->nbr_times_eat = ft_atoi(av[5]);
	else
		info->nbr_times_eat = -1;
	if (gettimeofday(&time, NULL) != 0)
	{
		// printf("HOLA");
		return (-1);
	}
	info->begin_time_in_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (0);
}
