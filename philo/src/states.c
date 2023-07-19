#include "../inc/philo.h"

long ft_actual_time(t_info *info)
{
	struct timeval actual_time;
	gettimeofday(&actual_time, NULL);
	return (actual_time.tv_sec - info->begin_time_in_ms.tv_usec);
}

void	ft_print_fork(t_philo *philo)
{
	printf("%ld %d has taken a fork\n", ft_actual_time(philo->info), philo->value);
}

void	ft_print_eating(t_philo *philo)
{
	printf("%ld %d is eating\n", ft_actual_time(philo->info), philo->value);
}

void	ft_print_sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", ft_actual_time(philo->info), philo->value);
}

void	ft_print_thinking(t_philo *philo)
{
	printf("%ld %d is thinking\n", ft_actual_time(philo->info), philo->value);
}

void	ft_print_died(t_philo *philo)
{
	printf("%ld %d died\n", ft_actual_time(philo->info), philo->value);
}


// ◦ timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died