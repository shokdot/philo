/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:02:18 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/17 18:12:42 by healeksa         ###   ########.fr       */
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
		return (3);
	// printf("%d\n", getpid());
	// init_clean(&data);
	// while (1)
	// {
	// 	/* code */
	// }
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	main2(argc, argv);
// 	printf("%d\n", getppid());
// 	// while (1)
// 	// {
// 	// 	/* code */
// 	// }
// 	// system("leaks philo");
// }
