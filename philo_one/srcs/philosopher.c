/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:24:19 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 17:03:24 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	even_philo(t_philo *philo, int r_fork, int l_fork)
{
	my_sleep(philo->opts->time_eat);
	while (!philo->opts->finish)
	{
		if (pickup_forks(philo, l_fork))
			break ;
		if (pickup_forks(philo, r_fork))
			break ;
		if (eating(philo))
			break ;
		return_forks(philo, r_fork);
		return_forks(philo, l_fork);
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
}

void	odd_philo(t_philo *philo, int r_fork, int l_fork)
{
	if (philo->philo_idx == philo->opts->num_philo)
		my_sleep(philo->opts->time_eat * 2);
	while (!philo->opts->finish)
	{
		if (pickup_forks(philo, r_fork))
			break ;
		if (philo->opts->num_philo == 1)
			break ;
		if (pickup_forks(philo, l_fork))
			break ;
		if (eating(philo))
			break ;
		return_forks(philo, l_fork);
		return_forks(philo, r_fork);
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
}

void	*philosopher(void *arg)
{
	t_philo	*philo;
	int		philo_idx;
	int		r_fork;
	int		l_fork;

	philo = (t_philo *)arg;
	philo_idx = philo->philo_idx;
	r_fork = philo_idx % philo->opts->num_philo;
	l_fork = philo_idx - 1;
	if (philo_idx % 2)
		odd_philo(philo, r_fork, l_fork);
	else
		even_philo(philo, r_fork, l_fork);
	pthread_mutex_unlock(&(philo->thds->mutexes[r_fork]));
	pthread_mutex_unlock(&(philo->thds->mutexes[l_fork]));
	pthread_mutex_unlock(&philo->thds->msg_mutex);
	return (NULL);
}
