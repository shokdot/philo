/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters_setters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:18:53 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/30 18:01:38 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	if (pthread_mutex_lock(mutex))
		return (false);
	*dest = value;
	if (pthread_mutex_unlock(mutex))
		return (false);
	return (true);
}

int	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	ret;

	if (pthread_mutex_lock(mutex))
		return (-1);
	ret = *value;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (ret);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	ret;

	if (pthread_mutex_lock(mutex))
		return (-1);
	ret = *value;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (ret);
}

bool	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	if (pthread_mutex_lock(mutex))
		return (false);
	*dest = value;
	if (pthread_mutex_unlock(mutex))
		return (false);
	return (true);
}
