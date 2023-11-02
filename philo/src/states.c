/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:44:36 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 00:54:31 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	ft_get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000));
}

long long	ft_get_time(t_inf *inf)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
		- inf->start_time);
}

void	ft_usleep(int ms)
{
	long int	start;

	start = ft_get_current_time();
	while (ft_get_current_time() - start < ms)
		usleep(ms / 10);
}

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->inf->writer);
	if (!ft_check_dead(0, philo->inf))
		printf("%lld %d %s\n", ft_get_time(philo->inf), philo->name, msg);
	pthread_mutex_unlock(&philo->inf->writer);
}
