/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:46:15 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/11 18:49:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(int argc, char **argv, t_data *in_data)
{
	if (argc == 5)
		in_data->meal_amount = -1;
	else
		in_data->meal_amount = ft_atoi(argv[5]);
	in_data->philo_num = ft_atoi(argv[1]);
	in_data->die_time = ft_atoi(argv[2]);
	in_data->eat_time = ft_atoi(argv[3]);
	in_data->sleep_time = ft_atoi(argv[4]);
}

int	parse(int argc, char **argv, t_data *in_data)
{
	if (argc < 5 || argc > 6)
		return (1);
	init_input(argc, argv, in_data);
	return (0);
}
