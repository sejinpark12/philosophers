/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:34:38 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 17:20:09 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_action.h"

int	pickup_forks(t_philo *philo, int fork_idx)
{
	pthread_mutex_t	*mutex;
	int				*permits;
	int				philo_idx;

	mutex = &(philo->thds->mutexes[fork_idx]);
	permits = philo->thds->permits;
	philo_idx = philo->philo_idx;
	pthread_mutex_lock(mutex);
	if (permits[fork_idx] == 1)
		permits[fork_idx] = 0;
	pthread_mutex_lock(&philo->thds->msg_mutex);
	if (philo->opts->finish)
		return (1);
//	philo->status = 1;
	printf("%ld %d has taken a fork\n", cal_time(philo->start_time), philo_idx);
	pthread_mutex_unlock(&philo->thds->msg_mutex);
	return (0);
}

int	eating(t_philo *philo)
{
	int	philo_idx;

	philo_idx = philo->philo_idx;
	pthread_mutex_lock(&philo->thds->msg_mutex);
	if (philo->opts->finish)
		return (1);
//	philo->status = 3;
	printf("%ld %d is eating\n", cal_time(philo->start_time), philo_idx);
	gettimeofday(&philo->last_eat_time, NULL);
	if (philo->eating_cnt < philo->opts->num_each_philo_eat)
	{
		philo->eating_cnt++;
		if (philo->eating_cnt == philo->opts->num_each_philo_eat)
		{
			pthread_mutex_lock(&philo->thds->complete_mutex);
			philo->thds->complete_philo_cnt++;
			pthread_mutex_unlock(&philo->thds->complete_mutex);
		}
	}
	pthread_mutex_unlock(&philo->thds->msg_mutex);
	my_sleep(philo->opts->time_eat);
	return (0);
}

void	return_forks(t_philo *philo, int fork_idx)
{
	int	num_philo;
	int	*permits;

	num_philo = philo->opts->num_philo;
	permits = philo->thds->permits;
	permits[fork_idx % num_philo] = 1;
	pthread_mutex_unlock(&(philo->thds->mutexes[fork_idx]));
}

int	sleeping(t_philo *philo)
{
	int	philo_idx;

	philo_idx = philo->philo_idx;
	pthread_mutex_lock(&philo->thds->msg_mutex);
	if (philo->opts->finish)
		return (1);
//	philo->status = 4;
	printf("%ld %d is sleeping\n", cal_time(philo->start_time), philo_idx);
	pthread_mutex_unlock(&philo->thds->msg_mutex);
	my_sleep(philo->opts->time_sleep);
	my_sleep(1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	int	philo_idx;

	philo_idx = philo->philo_idx;
	pthread_mutex_lock(&philo->thds->msg_mutex);
	if (philo->opts->finish)
		return (1);
//	philo->status = 0;
	printf("%ld %d is thinking\n", cal_time(philo->start_time), philo_idx);
	pthread_mutex_unlock(&philo->thds->msg_mutex);
	return (0);
}
