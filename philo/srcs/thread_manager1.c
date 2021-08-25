/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:46:18 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 16:56:10 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/thread_manager.h"

int	alloc_threads(t_data *data)
{
	int			num_philo;
	t_threads	*thds;

	num_philo = data->opts.num_philo;
	thds = &data->thds;
	data->thds.tids = NULL;
	data->thds.observ_tids = NULL;
	data->thds.mutexes = NULL;
	data->thds.permits = NULL;
	data->thds.tids = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);
	if (data->thds.tids == NULL)
		return (thread_manager_err("memory allocation error\n", thds));
	data->thds.observ_tids = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);
	if (data->thds.observ_tids == NULL)
		return (thread_manager_err("memory allocation error\n", thds));
	data->thds.mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_philo);
	if (data->thds.mutexes == NULL)
		return (thread_manager_err("memory allocation error\n", thds));
	data->thds.permits = (int *)malloc(sizeof(int) * num_philo);
	if (data->thds.permits == NULL)
		return (thread_manager_err("memory allocation error\n", thds));
	return (0);
}

int	init_mutex(t_data *data)
{
	int			i;
	int			num_philo;
	t_threads	*thds;

	i = 0;
	num_philo = data->opts.num_philo;
	thds = &data->thds;
	while (i < num_philo)
	{
		if (pthread_mutex_init(&(data->thds.mutexes[i]), NULL))
			return (thread_manager_err("pthread_mutex_init error\n", thds));
		i++;
	}
	memset(data->thds.permits, 1, num_philo);
	if (pthread_mutex_init(&data->thds.msg_mutex, NULL))
		return (thread_manager_err("pthread_mutex_init error\n", thds));
	if (pthread_mutex_init(&data->thds.complete_mutex, NULL))
		return (thread_manager_err("pthread_mutex_init error\n", thds));
	data->thds.complete_philo_cnt = 0;
	return (0);
}

int	create_threads(t_data *data)
{
	int			i;
	int			num_philo;
	t_threads	*thds;
	pthread_t	*tid;
	pthread_t	*ob_tid;

	i = 0;
	num_philo = data->opts.num_philo;
	thds = &data->thds;
	gettimeofday(&data->start_time, NULL);
	while (i < num_philo)
	{
		tid = &thds->tids[i];
		ob_tid = &thds->observ_tids[i];
		data->philos[i].last_eat_time = data->start_time;
		if (pthread_create(tid, NULL, philosopher, (void *)(&data->philos[i])))
			return (thread_manager_err("pthread_create error\n", thds));
		if (pthread_create(ob_tid, NULL, observer, (void *)(&data->philos[i])))
			return (thread_manager_err("pthread_create error\n", thds));
		i++;
	}
	return (0);
}

void	finish_threads(t_threads *thds, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_join(thds->tids[i], NULL);
		pthread_join(thds->observ_tids[i], NULL);
		pthread_mutex_destroy(&(thds->mutexes[i]));
		i++;
	}
	pthread_mutex_destroy(&(thds->msg_mutex));
	pthread_mutex_destroy(&(thds->complete_mutex));
	free_threads(thds);
}
