/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:02:18 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/30 19:05:30 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!parse(argc, argv, &data))
		return (1);
	else if (!data_init(&data))
		return (2);
	else if (!simulate(&data))
		return (init_clean(&data), 3);
	init_clean(&data);
	while (get_bool(&data.err_mtx, &data.err))
	{
		exit(1);
	}
	printf("%d\n", getpid());
	return (0);
}
