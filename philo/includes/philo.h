/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:04:09 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/20 14:36:26 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_TXT "\033[0;31mError\n\033[0;33m%s\033[0m\n"
# define USG_TXT "Invalid count of arguments"
# define TOO_BIG "Argument length is too long"
# define NEG_TXT "Argument can't be negative"
# define MAX_TXT "Maximum value of argument is INT_MAX"
# define WRONG_NUM "Philo num must be > 0 < 200, time > 60ms and < INT_MAX "
# define SYSCALL_ERR "System call error occurred!"

typedef struct s_philo
{
	int				philo_id;
	long			meal_count;
	long			last_eat;
	int				left_fork;
	int				right_fork;
	bool			is_full;
	pthread_t		thread_id;
	pthread_mutex_t	philo_data;
	struct s_data	*data;

}					t_philo;

typedef struct s_data
{
	long			philo_num;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			meal_amount;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log_mtx;
	pthread_mutex_t	data_catch;
	pthread_t		monitor;
	bool			all_ready;
	bool			end_simulation;
}					t_data;

// parsing init
bool				parse(int argc, char **argv, t_data *in_data);
bool				data_init(t_data *data);

// utils
void				throw_error(char *txt);
long				ft_atoi(char *str);
void				ft_free(void **ptr);
bool				simulation_ended(t_data *data);
void				ft_printf(t_data *data, char *txt, int id);

// simulation
bool				simulate(t_data *data);
bool				start_dinner(t_data *data);
bool				thread_creation(t_data *data);
void				*monitor(void *arg);

// stop end
bool				stop_simulation(t_data *data);
void				init_clean(t_data *data);

// time
long				timestamp(void);
void				ft_usleep(int ms, t_data *data);

// operations
void				eat(t_philo *philo);
void				sleep_philo(t_philo *philo);
void				think(t_philo *philo);

// forks
void				lock_forks(t_philo *philo);
void				unlock_forks(t_philo *philo);

// setters getters
void				set_bool(pthread_mutex_t *mutex, bool *dest, bool value,
						t_data *data);
void				set_long(pthread_mutex_t *mutex, long *dest, long value,
						t_data *data);
bool				get_bool(pthread_mutex_t *mutex, bool *value, t_data *data);
long				get_long(pthread_mutex_t *mutex, long *value, t_data *data);

#endif
