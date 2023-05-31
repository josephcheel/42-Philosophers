#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>
#include "libft/libft.h"


/*Allowed Functions
	memset, printf, malloc, free, write,
	usleep, gettimeofday, pthread_create,
	pthread_detach, pthread_join, pthread_mutex_init,
	pthread_mutex_destroy, pthread_mutex_lock,
	pthread_mutex_unlock*/

#

typedef struct s_info
{
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int nbr_times_eat;

	int begin_time_in_ms;
	int actual_time_in_ms;
	int	timestamp_in_ms;
}t_info;

int	ft_checker(int ac, char **av);
int	ft_create_threads(t_info *info);
void	ft_fill_info(int ac, char **av, t_info *info);