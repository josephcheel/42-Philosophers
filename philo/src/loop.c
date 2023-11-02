/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:44:49 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 01:08:43 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	if (philo->inf->nbr_of_philo == 1)
	{
		ft_usleep(philo->inf->time_to_die + 1);
		print_message(philo, "died");
		ft_check_dead(1, philo->inf);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	return ;
}

void	ft_eat(t_philo *philo)
{
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->inf->meal);
	philo->time_last_eat = ft_get_current_time();
	philo->meals_count++;
	if (philo->meals_count == philo->inf->nbr_of_meals)
		philo->inf->eaten++;
	pthread_mutex_unlock(&philo->inf->meal);
	ft_usleep(philo->inf->time_to_eat);
	return ;
}

void	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->inf->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}
