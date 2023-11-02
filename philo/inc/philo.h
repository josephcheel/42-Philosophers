/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:34:01 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 01:14:53 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_inf	t_inf;

typedef struct philo
{
	int					name;
	int					eating;
	int					meals_count;
	long int			time_last_eat;

	t_inf				*inf;

	pthread_mutex_t		lock;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
}t_philo;

typedef struct s_inf
{
	int					ac;
	int					dead;
	int					eaten;
	int					nbr_of_philo;
	int					nbr_of_meals;

	long int			start_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;

	t_philo				*philos;

	pthread_t			*ths;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writer;
	pthread_mutex_t		death;
	pthread_mutex_t		meal;
}t_inf;

// Initialization
int			ft_init(t_inf *inf, int ac, char **av);
int			ft_init_struct(t_inf *inf, int ac, char **av);
int			ft_init_alloc(t_inf *inf);
int			ft_init_mutex(t_inf *inf);
int			ft_init_philos(t_inf *inf);

// Checker
int			ft_isdigit(int c);
long		ft_atol(const char *str);
int			ft_atoi(const char *str);
int			ft_checker(int ac, char **av);

// Routine
void		*ft_routine(void *inf);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_pick_fork(t_philo *philo);
void		ft_drop_fork(t_philo *philo);
int			ft_check_dead(int set_dead, t_inf *inf);

// Thread
int			ft_create_threads(t_inf *inf);
void		*supervisor(void *data);

// Deleting
void		ft_delete(t_inf *inf, int forks, int general_mutex, int allocation);

// Time Management
long long	ft_get_current_time(void);
long long	ft_get_time(t_inf *inf);
void		ft_usleep(int ms);
void		print_message(t_philo *philo, char *msg);

#endif