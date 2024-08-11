/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:04:09 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/11 22:52:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define ERR_TXT "\033[0;31mError\n\033[0;33m%s\033[0m\n"
# define USG_TXT "Invalid count of arguments"
# define TOO_BIG "Argument length is too long"
# define NEG_TXT "Argument can't be negative"
# define MAX_TXT "Maximum value of argument is INT_MAX"

typedef struct s_data
{
	int	philo_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	meal_amount;
}		t_data;

bool	parse(int argc, char **argv, t_data *in_data);
void	throw_error(char *txt);
long	ft_atoi(char *str);
size_t	ft_strlen(const char *str);
bool	argv_valid(char *str);

#endif
