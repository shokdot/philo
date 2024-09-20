/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:53:48 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/20 12:04:28 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->philo_num)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->philos[i].philo_data);
			i++;
		}
		ft_free((void *)&data->forks);
	}
	if (data->philos)
		ft_free((void *)&data->philos);
	pthread_mutex_destroy(&data->log_mtx);
	pthread_mutex_destroy(&data->data_catch);
}

bool	stop_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if ((pthread_join(data->philos[i].thread_id, NULL)))
			return (false);
		i++;
	}
	if (pthread_join(data->monitor, NULL))
		return (false);
	init_clean(data);
	return (true);
}
