/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:46:15 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/18 17:19:04 by healeksa         ###   ########.fr       */
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

void	init_input(char **argv, t_data *in_data)
{
	if (argv[5])
		in_data->meal_amount = ft_atoi(argv[5]);
	else
		in_data->meal_amount = -1;
	in_data->philo_num = ft_atoi(argv[1]);
	in_data->die_time = ft_atoi(argv[2]) * 1000;
	in_data->eat_time = ft_atoi(argv[3]) * 1000;
	in_data->sleep_time = ft_atoi(argv[4]) * 1000;
}

bool	validate_input(t_data *in_data)
{
	if (in_data->philo_num > 200 || in_data->eat_time < 60000
		|| in_data->die_time < 60000 || in_data->sleep_time < 60000)
	{
		throw_error(WRONG_NUM);
		return (false);
	}
	return (true);
}

bool	parse(int argc, char **argv, t_data *in_data)
{
	if (!check_args(argc, argv))
		return (false);
	init_input(argv, in_data);
	if (!validate_input(in_data))
		return (false);
	return (true);
}
