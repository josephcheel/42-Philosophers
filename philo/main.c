/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:05:23 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/31 13:00:10 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usage(void)
{
	write(2, "\033[0;31mUsage: \
\033[0;36mnumber_of__philosophers \
\033[0;34mtime_to_die \
\033[0;32mtime_to_eat \
\033[0;35mtime_to_sleep \
\033[0;33m[number_of_times_each_philosopher_must_eat]\n", 156);
	return (-1);
}


int	main(int ac, char **av)
{
	t_info	info;
	
	if (!(ac == 5 || ac == 6))
		return (ft_usage());
	if (ft_checker(ac, av) != 0)
		return (-1);
	ft_fill_info(ac, av, &info);
	printf("%d\n", info.nbr_of_philo);
	printf("%d\n", info.time_to_die);
	printf("%d\n", info.time_to_eat);
	printf("%d\n", info.time_to_sleep);
	if (info.nbr_times_eat)
		printf("%d\n", info.nbr_times_eat);
	// if (ft_create_threads(&info) != 0)
	// 	return (-1);

}
