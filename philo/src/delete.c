/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:18:20 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/07/29 20:18:22 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_delete(t_inf *inf)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&inf->lock);
	pthread_mutex_destroy(&inf->writer);
	while (i++ < inf->nbr_of_philo)
	{
		pthread_mutex_destroy(&inf->forks[i]);
	}
	if (inf->forks)
		free(inf->forks);
	if (inf->philos)
		free(inf->philos);
}
