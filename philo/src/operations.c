/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:51:34 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/18 15:33:00 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	meal_cont_check(t_philo *philo)
{
	long	meal_count;
	long	meal_amount;
	t_data	*data;

	data = philo->data;
	meal_count = get_long(&philo->philo_data, &philo->meal_count, data);
	meal_amount = get_long(&data->data_catch, &data->meal_amount, data);
	if (meal_count == meal_amount)
	{
		set_bool(&philo->philo_data, &philo->is_full, true, philo->data);
		return (false);
	}
	return (true);
}

void	eat(t_philo *philo)
{
	meal_cont_check(philo);
	lock_forks(philo);
	ft_printf(philo->data, "is eating", philo->philo_id);
	pthread_mutex_lock(&philo->philo_data);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->philo_data);
	set_long(&philo->philo_data, &philo->last_eat, timestamp(), philo->data);
	ft_usleep(philo->data->eat_time / 1000, philo->data);
	unlock_forks(philo);
}

void	sleep_philo(t_philo *philo)
{
	ft_printf(philo->data, "is sleeping", philo->philo_id);
	ft_usleep(philo->data->sleep_time / 1000, philo->data);
}

void	think(t_philo *philo)
{
	ft_printf(philo->data, "is thinking", philo->philo_id);
}
