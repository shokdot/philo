/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:04:09 by healeksa          #+#    #+#             */
/*   Updated: 2024/08/11 00:27:14 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define ERR_TXT "\033[0;31mError\n\033[0;33m%s\033[0m\n"

int		parse(int argc, char **argv);
void	throw_error(char *txt);

#endif
