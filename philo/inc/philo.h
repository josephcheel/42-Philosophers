/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:34:01 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/07/31 11:48:45 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_inf	t_inf;

typedef struct philo
{
	int					name;
	int					eating;
	int					meals_count;
	int					finished;

	t_inf				*inf;
	time_t				time_last_eat;
	pthread_t			super;
	pthread_mutex_t		lock;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
}t_philo;

typedef struct s_inf
{
	int				dead;
	int				finished;
	int				nbr_of_philo;

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				eaten;

	time_t			start_time;
	t_philo			*philos;

	pthread_t		*ths;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writer;
	pthread_mutex_t	lock;
	pthread_mutex_t	meal;
}t_inf;

int	ft_checker(int ac, char **av);
void	ft_delete_table(t_philo **head);
// void	ft_create_philo(t_inf	*inf);
int	ft_create_threads(t_inf *inf);

void	ft_print_fork(t_inf *inf, int name);
void	ft_print_eating(t_philo *philo);
void	ft_print_sleeping(t_philo *philo);
void	ft_print_thinking(t_philo *philo);
void	ft_print_dead(t_philo *philo);

int	ft_pick_fork(t_philo *philo);
int	ft_drop_fork(t_philo *philo);
int	ft_sleep(t_philo *philo);
int	ft_eat(t_philo *philo);
int	ft_think(t_philo *philo);

void	*ft_routine(void *inf);
void	ft_delete(t_inf *inf);


int	ft_init(t_inf *inf,int ac,char **av);
int	ft_init_mutex(t_inf *inf);
int	ft_init_alloc(t_inf *inf);
int	ft_init_struct(t_inf *inf, int ac, char **av);

void	*meal_checks(void *data);

long long ft_actual_time(t_inf *inf);

#endif