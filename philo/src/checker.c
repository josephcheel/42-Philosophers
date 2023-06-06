#include "../inc/philo.h"

int	ft_isdigit_arg(int ac, char **av)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 1;
	while (i < ac)
	{
		// if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
		// {
		// 	write(2, "Error\n", 7);
		// 	exit(EXIT_FAILURE);
		// }
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