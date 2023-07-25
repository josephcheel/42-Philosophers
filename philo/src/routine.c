#include "../inc/philo.h"

void	*supervisor(void *data)
{
	t_philo *philo;

	philo = ((t_philo *)data);
	while(philo->inf->dead == 0)
	{
		pthread_mutex_lock(&philo->inf->lock);
		if (ft_actual_time(philo->inf) - philo->time_last_eat  > philo->inf->time_to_die && philo->eating == 0)
			philo->inf->dead = 1;
		//Comprobar muerte
		//Comprobar si duermen//comen//piensan(status)
		pthread_mutex_unlock(&philo->inf->lock);
	}
	return ((void *)0);
	//  ft_print_dead(philo);
}

void	*ft_routine(void *data)
{
	t_philo *philo;

	philo = ((t_philo *)data);
	pthread_create(&philo->super, NULL, &supervisor, philo);
	while (philo->inf->dead == 0)
	{
		ft_think(philo);
		ft_pick_fork(philo);
		ft_eat(philo);
		ft_drop_fork(philo);
		ft_sleep(philo);
		// picking the two forks needed, eating, dropping the forks and sleeping
		// break ;
	}
	ft_print_dead(philo);
	pthread_join(philo->super, NULL);

	// pthread_mutex_unlock(&philo->inf->writer);
	return (NULL);
}