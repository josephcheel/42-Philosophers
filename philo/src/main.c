/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:05:23 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/06/06 20:23:22 by jcheel-n         ###   ########.fr       */
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
\033[0;33m[number_of_times_each_philosopher_must_eat]\n", 156);
	return (-1);
}

// void	ft_printlist(t_philo *head, char *id)
// {
// 	t_philo	*temporary;

// 	temporary = head;
// 	printf("%s: ", id);
// 	printf("%d - ", temporary->value);
// 	temporary = temporary->next;
// 	while (!temporary->first)
// 	{
// 		printf("%d - ", temporary->value);
// 		temporary = temporary->next;
// 	}
// 	printf("\n");
// }

// void	ft_printforks(t_philo *head, char *id)
// {
// 	t_philo	*temporary;

// 	temporary = head;
// 	printf("%s: ", id);
// 	printf("%d ", temporary->value);
// 	printf("%d - ", temporary->fork);
// 	temporary = temporary->next;
// 	while (!temporary->first)
// 	{
// 		printf("%d ", temporary->value);
// 		printf("%d - ", temporary->fork);
// 		temporary = temporary->next;
// 	}
// 	printf("\n");
// }

int	main(int ac, char **av)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info *));
	if (!(ac == 5 || ac == 6))
		return (ft_usage());
	if (ft_checker(ac, av) != 0)
		return (-1);
	// info->table = ft_create_table(ft_atoi(av[1]));
	// if (!info->table)
	// {
	// 	ft_delete_table(&info->table);
	// 	free(info);
	// 	return (1);
	// }

	ft_fill_info(ac, av, info);

	// ft_create_philo(info);
	// printf("time to die %d\n", info->time_to_die);
	// ft_create_threads(info);
	// printf("time to die %d\n", info->time_to_die);
	// ft_printlist(table, "TABLE VALUES");
	// ft_printforks(table, "TABLE FORKS");
	return 0;
	// printf("%d", table->value);

	// ft_create_threads(&info);
	// printf("%d\n", info.nbr_of_philo);
	// printf("%d\n", info.time_to_die);
	// printf("%d\n", info.time_to_eat);
	// printf("%d\n", info.time_to_sleep);
	// if (info.nbr_times_eat)
	// 	printf("%d\n", info.nbr_times_eat);
	// if (ft_create_threads(&info) != 0)
	// 	return (-1);
}
