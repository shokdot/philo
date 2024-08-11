/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:04:09 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/11 18:48:39 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define ERR_TXT "\033[0;31mError\n\033[0;33m%s\033[0m\n"

typedef struct s_data
{
	int	philo_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	meal_amount;
}		t_data;

int		parse(int argc, char **argv, t_data *in_data);
void	throw_error(char *txt);
int		ft_atoi(char *str);

#endif
