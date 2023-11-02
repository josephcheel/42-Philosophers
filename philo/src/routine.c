/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:44:43 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 16:06:00 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_check_dead(int set_dead, t_inf *inf)
{
	pthread_mutex_lock(&inf->death);
	if (set_dead)
	{
		inf->dead = 1;
	}
	if (inf->dead)
	{
		pthread_mutex_unlock(&inf->death);
		return (1);
	}
	pthread_mutex_unlock(&inf->death);
	return (0);
}

void	ft_check_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->inf->meal);
	if (philo->inf->eaten == philo->inf->nbr_of_philo)
	{
		pthread_mutex_unlock(&philo->inf->meal);
		ft_check_dead(1, philo->inf);
		return ;
	}
	pthread_mutex_unlock(&philo->inf->meal);
	return ;
}

void	*supervisor(void *data)
{
	t_philo	*philo;

	philo = ((t_philo *)data);
	pthread_mutex_lock(&philo->inf->meal);
	if (!ft_check_dead(0, philo->inf) && ft_get_current_time()
		- philo->time_last_eat > (long)(philo->inf->time_to_die))
	{
		pthread_mutex_unlock(&philo->inf->meal);
		print_message(philo, "died");
		ft_check_dead(1, philo->inf);
	}
	pthread_mutex_unlock(&philo->inf->meal);
	if (philo->inf->ac == 6)
		ft_check_meal(philo);
	return (NULL);
}

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = ((t_philo *)data);
	if (philo->name % 2 == 0)
		ft_usleep(philo->inf->time_to_eat / 10);
	while (!ft_check_dead(0, philo->inf))
	{
		ft_pick_fork(philo);
		ft_eat(philo);
		ft_drop_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
