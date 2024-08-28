/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:55:40 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/28 21:21:03 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = timestamp();
	data->philos = malloc(data->philo_num * sizeof(t_philo));
	if (!data->philos)
		return (false);
	while (data->philo_num > i)
	{
		data->philos[i].philo_id = i;
		data->philos[i].meal_count = 0;
		data->philos[i].last_eat = 0;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->philo_num;
		data->philos[i].data = data;
		i++;
	}
	return (true);
}

bool	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->philo_num * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (init_clean(data), false);
	while (data->philo_num > i)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (init_clean(data), false);
		i++;
	}
	if (pthread_mutex_init(&data->log_mtx, NULL) != 0)
		return (init_clean(data), false);
	return (true);
}

bool	data_init(t_data *data)
{
	if (!init_philos(data) || !init_mutex(data))
		return (false);
	return (true);
}
