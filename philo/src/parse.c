/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:46:15 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/01 15:13:07 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		throw_error(USG_TXT);
		return (false);
	}
	while (argv[i])
	{
		if (!argv_valid(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

void	init_input(char **argv, t_data *data)
{
	if (argv[5])
		data->meal_amount = ft_atoi(argv[5]);
	else
		data->meal_amount = -1;
	data->philo_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]) * 1000;
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	data->end_simulation = false;
	data->all_ready = false;
}

bool	validate_input(t_data *data)
{
	if (data->philo_num > 200 || data->philo_num == 0 || data->eat_time < 60000
		|| data->die_time < 60000 || data->sleep_time < 60000)
	{
		throw_error(WRONG_NUM);
		return (false);
	}
	return (true);
}

bool	parse(int argc, char **argv, t_data *data)
{
	if (!check_args(argc, argv))
		return (false);
	init_input(argv, data);
	if (!validate_input(data))
		return (false);
	return (true);
}
