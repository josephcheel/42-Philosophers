/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:45:02 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 01:11:58 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit_arg(int ac, char **av)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > (long)INT_MAX || ft_atol(av[i]) < (long)INT_MIN)
		{
			write(2, "Error\n", 7);
			return (-1);
		}
		while (av[i][nbr])
		{
			if (!(ft_isdigit(av[i][nbr])))
			{
				write(2, "Error\n", 7);
				return (-1);
			}
			nbr++;
		}
		nbr = 0;
		i++;
	}
	return (0);
}

int	ft_checker(int ac, char **av)
{
	if (ft_isdigit_arg(ac, av) != 0)
		return (-1);
	return (0);
}
