/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:51:58 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/01 13:30:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	busy_waiting(void)
{
	printf("LOL\n");
}

void	*dinner(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	printf("ugrop\n");
	set_bool(&data->err_mtx, &data->err, true);
	busy_waiting();
	return (NULL);
}

bool	thread_creation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, dinner, data))
		{
			while (i > 0)
			{
				i--;
				pthread_detach(data->philos[i].thread_id);
			}
			return (false);
		}
		i++;
	}
	data->start_time = timestamp();
	set_bool(&data->all_ready_mtx, &data->all_ready, true);
	stop_simulation(data);
	return (true);
}
