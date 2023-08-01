#include "../inc/philo.h"

long long	ft_actual_time(t_inf *inf)
{
	struct timeval	actual_time;

	gettimeofday(&actual_time, NULL);
	return ((actual_time.tv_sec * 1000 + actual_time.tv_usec / 1000)
		- inf->start_time);
}

void	ft_print_fork(t_inf *inf, int name)
{
	pthread_mutex_lock(&inf->writer);
	if (inf->finished != 1)
		printf("%lld %d has taken a fork\n", ft_actual_time(inf), name);
	pthread_mutex_unlock(&inf->writer);
}

void	ft_print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->inf->writer);
	if (philo->inf->finished != 1)
		printf("%lld %d is eating\n", ft_actual_time(philo->inf), philo->name);
	pthread_mutex_unlock(&philo->inf->writer);
}

void	ft_print_sleeping(t_philo *philo)
{	
	pthread_mutex_lock(&philo->inf->writer);
	if (philo->inf->finished != 1)
		printf("%lld %d is sleeping\n", ft_actual_time(philo->inf), philo->name);
	pthread_mutex_unlock(&philo->inf->writer);
}

void	ft_print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->inf->writer);
	if (philo->inf->finished != 1)
		printf("%lld %d is thinking\n", ft_actual_time(philo->inf), philo->name);
	pthread_mutex_unlock(&philo->inf->writer);
}

void	ft_print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->inf->writer);
	if (philo->inf->finished != 1)
		printf("%lld %d died\n", ft_actual_time(philo->inf), philo->name);
	pthread_mutex_unlock(&philo->inf->writer);
}
