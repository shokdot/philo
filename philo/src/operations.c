/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:51:34 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/19 16:42:23 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	full_check(t_data *data)
{
	int	i;

	if (get_long(&data->data_catch, &data->meal_amount, data) == -1)
		return ;
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philos[i].philo_data);
		if (data->philos[i].is_full == false)
		{
			pthread_mutex_unlock(&data->philos[i].philo_data);
			break ;
		}
		pthread_mutex_unlock(&data->philos[i].philo_data);
		i++;
	}
	if (i == data->philo_num)
	{
		set_bool(&data->data_catch, &data->end_simulation, true, data);
		return ;
	}
}

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
	lock_forks(philo);
	ft_printf(philo->data, "is eating", philo->philo_id);
	set_long(&philo->philo_data, &philo->last_eat, timestamp(), philo->data);
	ft_usleep(philo->data->eat_time / 1000, philo->data);
	pthread_mutex_lock(&philo->philo_data);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->philo_data);
	meal_cont_check(philo);
	full_check(philo->data);
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
