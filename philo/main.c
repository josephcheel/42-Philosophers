#include "philo.h"

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!ft_checker(av))
		{
			write(2, "Error\n", 7);
			return (-1);
		}
		return (0);
	}

	write(2, "\033[0;31mUsage: \
\033[0;36mnumber_of__philosophers \
\033[0;34mtime_to_die \
\033[0;32mtime_to_eat \
\033[0;35mtime_to_sleep \
\033[0;33m[number_of_times_each_philosopher_must_eat]\
\n", 156);
}
