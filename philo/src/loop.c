#include "../inc/philo.h"

int	ft_pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_print_fork(philo->inf, philo->name);
	pthread_mutex_lock(philo->left_fork);
	ft_print_fork(philo->inf, philo->name);
	return (0);
}
int	ft_eat(t_philo *philo)
{
	ft_print_eating(philo);
	philo->eating = 1;
	pthread_mutex_lock(&philo->lock);
	usleep(philo->inf->time_to_eat * 1000);
	philo->time_last_eat = ft_actual_time(philo->inf);
	philo->eating = 0;
	philo->meals_count += 1;
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

int	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_print_sleeping(philo);
	usleep(philo->inf->time_to_sleep * 1000);
	return (0);
}

int	ft_think(t_philo *philo)
{
	ft_print_thinking(philo);
	return (0);
}