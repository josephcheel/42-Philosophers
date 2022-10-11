#include "philo.h"

int	ft_isdigit_arg(char **av)
{
	int	i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);

}

int	ft_checker(char **av)
{
	if (!ft_isdigit_arg(av))
		return (0);
	return (1);
}