/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:44:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/30 16:56:20 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_init_mutex(t_inf *inf)
{
	int	nbr;

	nbr = -1;
	if (pthread_mutex_init(&inf->death, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&inf->writer, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&inf->meal, NULL) != 0)
		return (-1);
	while (nbr++ < inf->nbr_of_philo)
		if (pthread_mutex_init(&inf->forks[nbr], NULL) != 0)
			return (-1);
	return (0);
}

int	ft_init_alloc(t_inf *inf)
{
	inf->forks = malloc(sizeof(pthread_mutex_t) * inf->nbr_of_philo);
	if (!inf->forks)
		return (1);
	inf->ths = malloc(sizeof(pthread_t) * inf->nbr_of_philo);
	if (!inf->ths)
		return (1);
	inf->philos = malloc(sizeof(t_philo) * inf->nbr_of_philo);
	if (!inf->philos)
		return (-1);
	return (0);
}

int	ft_init_forks(t_inf *inf)
{
	int	i;

	i = 1;
	while (i < inf->nbr_of_philo)
	{
		inf->philos[i].left_fork = &inf->forks[i];
		inf->philos[i].right_fork = &inf->forks[i - 1];
		i++;
	}
	inf->philos[0].left_fork = &inf->forks[0];
	inf->philos[0].right_fork = &inf->forks[inf->nbr_of_philo - 1];
	return (0);
}

int	ft_init_philos(t_inf	*inf)
{
	int	nbr;

	nbr = -1;
	ft_init_forks(inf);
	while (++nbr < inf->nbr_of_philo)
	{
		inf->philos[nbr].name = nbr + 1;
		inf->philos[nbr].time_last_eat = 0;
		inf->philos[nbr].meals_count = 0;
		inf->philos[nbr].inf = inf;
	}
	return (0);
}

int	ft_init_struct(t_inf *inf, int ac, char **av)
{
	inf->nbr_of_philo = ft_atoi(av[1]);
	inf->time_to_die = ft_atoi(av[2]);
	inf->time_to_eat = ft_atoi(av[3]);
	inf->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		inf->nbr_of_meals = ft_atoi(av[5]);
	inf->start_time = ft_get_current_time();
	inf->dead = 0;
	inf->eaten = 0;
	inf->ac = ac;
	return (0);
}
