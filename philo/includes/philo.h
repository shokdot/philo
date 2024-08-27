/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:04:09 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/27 20:37:54 by healeksa         ###   ########.fr       */
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
	int				meal_count;
	int				last_eat;
	int				left_fork;
	int				right_fork;
	pthread_t		thread_id;
	struct s_data	*data;

}					t_philo;

typedef struct s_data
{
	long			philo_num;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			meal_amount;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log_mtx;
}					t_data;

bool				parse(int argc, char **argv, t_data *in_data);
void				throw_error(char *txt);
long				ft_atoi(char *str);
bool				argv_valid(char *str);
bool				data_init(t_data *data);
void				ft_free(void **ptr);
bool				simulate(t_data *data);
void				init_clean(t_data *data);

#endif
