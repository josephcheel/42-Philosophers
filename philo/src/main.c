/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:05:23 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/02 17:05:43 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_usage(void)
{
	write(2, "\033[0;31mUsage: \
\033[0;36mnumber_of__philosophers \
\033[0;34mtime_to_die \
\033[0;32mtime_to_eat \
\033[0;35mtime_to_sleep \
\033[0;33m[number_of_times_each_philosopher_must_eat]\n\033[0m", 160);
	return (-1);
}

int	ft_init(t_inf *inf, int ac, char **av)
{
	ft_init_struct(inf, ac, av);
	if (ft_init_alloc(inf) != 0 || ft_init_mutex(inf) != 0)
	{
		ft_delete(inf, 0, 0, 1);
		return (1);
	}
	ft_init_philos(inf);
	return (0);
}

int	main(int ac, char **av)
{
	t_inf	inf;

	if (!(ac == 5 || ac == 6))
		return (ft_usage());
	if (ft_checker(ac, av) != 0)
		return (-1);
	if (ft_init(&inf, ac, av) != 0)
		return (-1);
	ft_create_threads(&inf);
	ft_delete(&inf, 1, 1, 1);
	return (0);
}
