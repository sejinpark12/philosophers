/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:27:23 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 16:35:49 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTION_H
# define PHILO_ACTION_H
# include <stdio.h>
# include <unistd.h>
# include "structs.h"
# include "utils.h"

int		pickup_forks(t_philo *philo, int fork_idx);
int		eating(t_philo *philo);
void	return_forks(t_philo *philo, int fork_idx);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

#endif
