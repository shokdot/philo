/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:32:43 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/28 21:39:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
