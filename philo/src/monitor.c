/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:53:58 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/17 18:42:27 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dead_check(t_data *data, int *full_count)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philos[i].philo_data);
		if (data->philos[i].is_full)
			(*full_count)++;
		if (timestamp() - data->philos[i].last_eat >= data->die_time / 1000)
		{
			ft_printf(data, "died", data->philos[i].philo_id);
			pthread_mutex_unlock(&data->philos[i].philo_data);
			return (true);
		}
		pthread_mutex_unlock(&data->philos[i].philo_data);
		i++;
	}
	return (false);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		full_count;

	data = (t_data *)arg;
	full_count = 0;
	while (!simulation_ended(data))
	{
		if (dead_check(data, &full_count))
		{
			set_bool(&data->data_catch, &data->end_simulation, true, data);
			break ;
		}
		if (full_count == data->meal_amount)
		{
			set_bool(&data->data_catch, &data->end_simulation, true, data);
			break ;
		}
	}
	return (NULL);
}
