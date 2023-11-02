/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:44:58 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 16:01:03 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_start_checking(t_inf *inf)
{
	int	i;

	ft_usleep(inf->time_to_die + 1);
	while (!ft_check_dead(0, inf))
	{
		i = 0;
		while (i < inf->nbr_of_philo)
		{
			supervisor(&inf->philos[i]);
			i++;
		}
	}
}

int	ft_create_threads(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->nbr_of_philo)
	{
		if (pthread_create(&inf->ths[i], NULL,
				&ft_routine, &(inf->philos[i])) != 0)
			return (-1);
	}
	ft_start_checking(inf);
	i = -1;
	while (++i < inf->nbr_of_philo)
	{
		if (pthread_join(inf->ths[i], NULL) != 0)
			return (-1);
	}
	return (0);
}
