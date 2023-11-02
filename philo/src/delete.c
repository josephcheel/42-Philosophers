/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:18:20 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/02 17:09:27 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_delete(t_inf *inf, int forks, int general_mutex, int allocation)
{
	int	i;

	i = -1;
	if (forks)
	{
		while (++i < inf->nbr_of_philo)
			pthread_mutex_destroy(&inf->forks[i]);
	}
	if (general_mutex)
	{
		if (inf->forks)
			free(inf->forks);
		if (inf->philos)
			free(inf->philos);
		if (inf->ths)
			free(inf->ths);
	}
	if (allocation)
	{
		pthread_mutex_destroy(&inf->writer);
		pthread_mutex_destroy(&inf->death);
		pthread_mutex_destroy(&inf->meal);
	}
}
