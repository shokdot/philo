/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:46:15 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/11 22:21:22 by healeksa         ###   ########.fr       */
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
		if (ft_strlen(argv[i]) > 10)
		{
			throw_error(TOO_BIG);
			return (false);
		}
		i++;
	}
	return (true);
}

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

bool	parse(int argc, char **argv, t_data *in_data)
{
	if (!check_args(argc, argv))
		return (false);
	// init_input(argc, argv, in_data);
	return (true);
}
