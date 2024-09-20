/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:01:04 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/20 11:27:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&data->forks[0]);
	printf("0 1 has taken a fork\n");
	ft_usleep(data->die_time / 1000, data);
	printf("%lu 1 died\n", data->die_time / 1000);
	pthread_mutex_unlock(&data->forks[0]);
	return (NULL);
}

bool	one_philo(t_data *data)
{
	if (pthread_create(&data->philos[0].thread_id, NULL, one, &data->philos[0]))
		return (false);
	if (pthread_join(data->philos[0].thread_id, NULL))
		return (false);
	init_clean(data);
	return (true);
}

bool	start_dinner(t_data *data)
{
	if (!thread_creation(data))
		return (false);
	else if (!stop_simulation(data))
		return (false);
	return (true);
}

bool	simulate(t_data *data)
{
	if (data->meal_amount == 0)
		return (false);
	else if (data->philo_num == 1)
		return (one_philo(data));
	else
		return (start_dinner(data));
	return (true);
}
