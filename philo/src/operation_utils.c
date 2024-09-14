/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:08:44 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/13 12:34:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_printf(philo->data, "has taken a fork", philo->philo_id);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_printf(philo->data, "has taken a fork", philo->philo_id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		ft_printf(philo->data, "has taken a fork", philo->philo_id);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		ft_printf(philo->data, "has taken a fork", philo->philo_id);
	}
}

void	unlock_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
}

void	ft_printf(t_data *data, char *txt, int id)
{
	if (simulation_ended(data))
		return ;
	pthread_mutex_lock(&data->log_mtx);
	printf("%lld %d %s\n", timestamp() - data->start_time, id, txt);
	pthread_mutex_unlock(&data->log_mtx);
}
