/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:05:23 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/07/25 15:14:03 by jcheel-n         ###   ########.fr       */
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
	t_inf	inf;

	// inf = (t_inf *)malloc(sizeof(t_inf *));
	if (!(ac == 5 || ac == 6))
		return (ft_usage());
	if (ft_checker(ac, av) != 0)
		return (-1);
	ft_init(&inf, ac, av);
	ft_create_threads(&inf);
	ft_delete(&inf);
	return (0);
}
