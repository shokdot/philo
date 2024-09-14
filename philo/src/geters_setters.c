/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:18:53 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/02 22:06:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value, t_data *data)
{
	if (pthread_mutex_lock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
	*dest = value;
	if (pthread_mutex_unlock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
}

bool	get_bool(pthread_mutex_t *mutex, bool *value, t_data *data)
{
	bool	ret;

	if (pthread_mutex_lock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
	ret = *value;
	if (pthread_mutex_unlock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
	return (ret);
}

long	get_long(pthread_mutex_t *mutex, long *value, t_data *data)
{
	long	ret;

	if (pthread_mutex_lock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
	ret = *value;
	if (pthread_mutex_unlock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value, t_data *data)
{
	if (pthread_mutex_lock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
	*dest = value;
	if (pthread_mutex_unlock(mutex))
	{
		pthread_mutex_lock(&data->data_catch);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->data_catch);
	}
}
