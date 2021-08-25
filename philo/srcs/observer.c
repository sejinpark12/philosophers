/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:26:06 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/23 23:37:36 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/observer.h"

void	*simulation_stop(t_philo *philo)
{
	philo->opts->finish = 1;
	pthread_mutex_unlock(&philo->thds->msg_mutex);
	return (NULL);
}

void	*observer(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->opts->finish)
	{
		pthread_mutex_lock(&philo->thds->msg_mutex);
		if (!philo->opts->finish
			&& cal_time(&philo->last_eat_time) > philo->opts->time_die / 1000)
		{
			printf("%ld %d died\n",
				cal_time(philo->start_time), philo->philo_idx);
			return (simulation_stop(philo));
		}
		if (!philo->opts->finish
			&& philo->opts->num_philo == philo->thds->complete_philo_cnt)
		{
			printf("%ld all philosophers ate %d times\n",
				cal_time(philo->start_time), philo->opts->num_each_philo_eat);
			return (simulation_stop(philo));
		}
		pthread_mutex_unlock(&philo->thds->msg_mutex);
		usleep(1000);
	}
	return (NULL);
}
