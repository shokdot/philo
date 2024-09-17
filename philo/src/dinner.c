/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:51:58 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/17 19:23:04 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	busy_waiting(t_data *data)
{
	while (!get_bool(&data->data_catch, &data->all_ready, data)
		&& !simulation_ended(data))
		;
	// ft_usleep(100, data);
}

void	*dinner(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	busy_waiting(philo->data);
	if (philo->philo_id % 2 == 0)
		ft_usleep(100, data);
	while (!simulation_ended(data))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}

bool	thread_creation(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_create(&data->monitor, NULL, &monitor, data))
		return (false);
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, dinner,
				&data->philos[i]))
		{
			while (i > 0)
			{
				i--;
				pthread_detach(data->philos[i].thread_id);
			}
			pthread_detach(data->monitor);
			return (false);
		}
		i++;
	}
	set_long(&data->data_catch, &data->start_time, timestamp(), data);
	set_bool(&data->data_catch, &data->all_ready, true, data);
	return (true);
}
