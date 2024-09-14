/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:53:58 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/14 14:55:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!simulation_ended(data))
	{
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->philos[i].philo_data);
			if (timestamp() - data->philos[i].last_eat >= data->die_time / 1000)
			{
				printf("%lld %d died\n", timestamp() - data->start_time,
					data->philos[i].philo_id);
				set_bool(&data->data_catch, &data->end_simulation, true, data);
				break ;
			}
			pthread_mutex_unlock(&data->philos[i].philo_data);
			i++;
		}
	}
	return (NULL);
}
