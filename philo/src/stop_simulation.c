/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:53:48 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/17 19:33:44 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	{
		return (false);
	}
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	return (true);
}

void	init_clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos)
		ft_free((void *)data->philos);
	if (data->forks)
	{
		while (i < data->philo_num)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		ft_free((void *)data->forks);
	}
}
