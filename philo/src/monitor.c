/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:53:58 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/18 15:31:40 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dead_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philos[i].philo_data);
		if (timestamp() - data->philos[i].last_eat >= data->die_time / 1000)
		{
			ft_printf(data, "died", data->philos[i].philo_id);
			set_bool(&data->data_catch, &data->end_simulation, true, data);
			pthread_mutex_unlock(&data->philos[i].philo_data);
			return (true);
		}
		pthread_mutex_unlock(&data->philos[i].philo_data);
		i++;
	}
	return (false);
}

bool	full_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philos[i].philo_data);
		if (data->philos[i].is_full == false)
		{
			pthread_mutex_unlock(&data->philos[i].philo_data);
			break ;
		}
		pthread_mutex_unlock(&data->philos[i].philo_data);
		i++;
	}
	if (i == data->philo_num)
	{
		set_bool(&data->data_catch, &data->end_simulation, true, data);
		return (true);
	}
	return (false);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!simulation_ended(data))
	{
		if (dead_check(data))
			break ;
		if (full_check(data))
			break ;
	}
	return (NULL);
}
