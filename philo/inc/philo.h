/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:34:01 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/07/20 02:59:55 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>
#include "../libft/libft.h"
#include <stdbool.h>

typedef struct	s_info	t_info;

typedef struct philo
{
	int				name;
	pthread_t			th; 
	bool			right_fork;
	bool			left_fork;

}t_philo;

typedef struct	s_info
{
	bool		dead;
	int			nbr_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_times_eat;

	time_t 	begin_time_in_ms;
	t_philo			*philo;
	pthread_mutex_t	*mutex;
}t_info;



/*Allowed Functions
	memset, printf, malloc, free, write,
	usleep, gettimeofday, pthread_create,
	pthread_detach, pthread_join, pthread_mutex_init,
	pthread_mutex_destroy, pthread_mutex_lock,
	pthread_mutex_unlock*/


int	ft_checker(int ac, char **av);
int	ft_fill_info(int ac, char **av, t_info *philo);

// t_philo	*ft_create_table(int size);
void	ft_delete_table(t_philo **head);
void	ft_create_philo(t_info	*info);
int	ft_create_threads(t_info *info);
void	ft_create_multiple_mutex(t_info *info);

void	ft_print_fork(t_philo *philo);
void	ft_print_eating(t_philo *philo);
void	ft_print_sleeping(t_philo *philo);
void	ft_print_thinking(t_philo *philo);
void	ft_print_died(t_philo *philo);