/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:51:58 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/30 15:56:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	printf("lol\n");
	return (NULL);
}

bool	thread_creation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, dinner, data))
		{
			while (i > 0)
			{
				i--;
				pthread_detach(data->philos[i].thread_id);
			}
			return (false);
		}
		i++;
	}
	return (true);
}
