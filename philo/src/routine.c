#include "../inc/philo.h"

void	*meal_checks(void *data)
{
	t_inf *inf;

	inf = ((t_inf *)data);
	// printf("HOLA");
	while(inf->dead == 0)
	{
		pthread_mutex_lock(&inf->lock);
		if (inf->eaten == inf->nbr_of_philo)
			inf->dead = 1;
		// printf("DEATH %d", inf->dead);
		pthread_mutex_unlock(&inf->lock);
	}
	return (NULL);
}

void	*supervisor(void *data)
{
	t_philo *philo;

	philo = ((t_philo *)data);
	while(philo->inf->dead == 0)
	{
		pthread_mutex_lock(&philo->inf->lock);
		if (ft_actual_time(philo->inf) - philo->time_last_eat  > philo->inf->time_to_die && 
			philo->eating == 0 && philo->inf->dead == 0)
			philo->inf->dead = 1;
		if (philo->meals_count == philo->inf->nbr_of_meals && philo->finished == 0 )
		{
			philo->inf->eaten += 1;
			philo->finished = 1;
		}
		if (philo->inf->eaten == philo->inf->nbr_of_philo)
		{
			philo->inf->finished = 1;	
			philo->inf->dead = 1;
		}
		pthread_mutex_unlock(&philo->inf->lock);
	}
	return (NULL);
}

void	*ft_routine(void *data)
{
	t_philo *philo;

	philo = ((t_philo *)data);
	pthread_create(&philo->super, NULL, &supervisor, philo);
	// printf("INFO EATEN: %d\n", philo->inf->eaten);
	while (philo->inf->dead == 0)
	{
		ft_pick_fork(philo);
		ft_eat(philo);
		ft_drop_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	pthread_join(philo->super, NULL);
	pthread_mutex_lock(&philo->lock);
	if (philo->inf->finished == 0 && philo->inf->dead == 1)
	{	
		ft_print_dead(philo);
		philo->inf->finished = 1;
	}	
	pthread_mutex_unlock(&philo->lock);	
	return (NULL);
}