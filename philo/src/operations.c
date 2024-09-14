/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:51:34 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/13 16:04:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	meal_cont_check(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->data_catch))
	{
		set_bool(&philo->data->data_catch, &philo->data->end_simulation, true,
			philo->data);
		return (false);
	}
	if (philo->meal_count == philo->data->meal_amount)
	{
		if (pthread_mutex_unlock(&philo->data->data_catch))
		{
			set_bool(&philo->data->data_catch, &philo->data->end_simulation,
				true, philo->data);
			return (false);
		}
		return (true);
	}
	if (pthread_mutex_unlock(&philo->data->data_catch))
	{
		set_bool(&philo->data->data_catch, &philo->data->end_simulation, true,
			philo->data);
		return (false);
	}
	return (false);
}

bool	eat(t_philo *philo)
{
	// if (meal_cont_check(philo))
	// 	return (true);
	lock_forks(philo);
	ft_printf(philo->data, "is eating", philo->philo_id);
	// set_long(&philo->philo_data, (long)philo->last_eat, timestamp(),
	// philo->data);
	// pthread_mutex_lock(&philo->philo_data);
	// philo->last_eat = timestamp(); // set_long
	// if (philo->philo_id == 0)
	// 	printf("%ld\n", philo->meal_count);
	philo->meal_count++;
	set_long(&philo->philo_data, &philo->last_eat, timestamp(), philo->data);
	ft_usleep(philo->data->eat_time / 1000, philo->data);
	// pthread_mutex_unlock(&philo->philo_data);
	unlock_forks(philo);
	// printf("before == %ld \n", philo->last_eat);
	// printf("after == %ld \n", philo->last_eat);
	return (true);
}

void	sleep_philo(t_philo *philo)
{
	ft_printf(philo->data, "is sleeping", philo->philo_id);
	ft_usleep(philo->data->sleep_time / 1000, philo->data);
}

bool	think(t_philo *philo)
{
	// if (philo->meal_count == 0)
	// 	return (true);
	ft_printf(philo->data, "is thinking", philo->philo_id);
	return (true);
}
