/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:26:19 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/15 00:13:25 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include "structs.h"
# include "utils.h"

void    pickup_forks(t_philo *philo, int fork_idx);
void    return_forks(t_philo *philo, int fork_idx);
void	*philosopher(void *arg);
void    *oddphilosopher(void *arg);

#endif
