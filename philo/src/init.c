/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:55:40 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/17 18:50:17 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philos(t_data *data)
{
	int	i;

	i = 0;
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
		i++;
	}
	return (true);
}

bool	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->philo_num * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (false);
	while (data->philo_num > i)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (true);
}

bool	data_init(t_data *data)
{
	if (!init_philos(data) || !init_forks(data))
		return (false);
	return (true);
}
