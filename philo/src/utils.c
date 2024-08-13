/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:15:51 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/13 11:56:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	throw_error(char *txt)
{
	printf(ERR_TXT, txt);
}

long	ft_atoi(char *str)
{
	long	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	if (res > INT_MAX)
		return (0);
	return (res);
}

bool	argv_valid(char *str)
{
	int	len;

	len = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		throw_error(NEG_TXT);
		return (false);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		len++;
		str++;
	}
	if (len > 10)
	{
		throw_error(MAX_TXT);
		return (false);
	}
	return (true);
}
