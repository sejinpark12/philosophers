/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:46:18 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/17 01:33:49 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/thread_manager.h"

void free_threads(t_threads *thds)
{
    free(thds->tids);
    free(thds->observ_tids);
    free(thds->mutexes);
    free(thds->permits);
}

int memory_alloc_err(t_threads *thds)
{
    free_threads(thds);
    printf("memory allocation error\n");
    return (1);
}

int alloc_threads(t_data *data)
{
    data->thds.tids = NULL;
    data->thds.observ_tids = NULL;
    data->thds.mutexes = NULL;
    data->thds.permits = NULL;
    data->thds.tids = (pthread_t*)malloc(sizeof(pthread_t) * data->opts.num_philo);
    if (data->thds.tids == NULL)
        return (memory_alloc_err(&data->thds));
    data->thds.observ_tids = (pthread_t*)malloc(sizeof(pthread_t) * data->opts.num_philo);
    if (data->thds.observ_tids == NULL)
        return (memory_alloc_err(&data->thds));
    data->thds.mutexes = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * data->opts.num_philo);
    if (data->thds.mutexes == NULL)
        return (memory_alloc_err(&data->thds));
    data->thds.permits = (int*)malloc(sizeof(int) * data->opts.num_philo);
    if (data->thds.permits == NULL)
        return (memory_alloc_err(&data->thds));
    return (0);
}

int init_mutex(t_data *data)
{
    int i;
    int num_philo;

    i = 0;
    num_philo = data->opts.num_philo;
    while (i < num_philo)
    {
	    if (pthread_mutex_init(&(data->thds.mutexes[i]), NULL))
        {
            free_threads(&data->thds);
            printf("pthread_mutex_init error\n");
            return (1);
        }
        i++;
    }
    memset(data->thds.permits, 1, num_philo);
    if (pthread_mutex_init(&data->thds.msg_mutex, NULL))
    {
        free_threads(&data->thds);
        printf("pthread_mutex_init error\n");
        return (1);
    }
    return (0);
}

int create_threads(t_data *data)
{
    int         i;
    int         num_philo;
    t_threads   *thds;
    pthread_t   *tid;
    pthread_t   *observ_tid;

    i = 0;
    num_philo = data->opts.num_philo;
    thds = &data->thds;
    gettimeofday(&data->start_time, NULL);
    while (i < num_philo)
	{
        tid = &thds->tids[i];
        observ_tid = &thds->observ_tids[i];
        data->philos[i].last_eat_time = data->start_time;
		if ((i + 1) % 2 && pthread_create(tid, NULL, oddphilosopher, (void*)(&data->philos[i])))
        {
            free_threads(thds);
            printf("pthread_create error\n");
            return (1);
        }
		if ((i + 1) % 2 == 0 && pthread_create(tid, NULL, philosopher, (void*)(&data->philos[i])))
        {
            free_threads(thds);
            printf("pthread_create error\n");
            return (1);
        }
        if (pthread_create(observ_tid, NULL, observer, (void*)(&data->philos[i])))
        {
            free_threads(thds);
            printf("pthread_create error\n");
            return (1);
        }
        i++;
	}
    return (0);
}

void finish_threads(t_threads *thds, int num_philo)
{
    int i;

    i = 0;
    while (i < num_philo)
    {
		pthread_join(thds->tids[i], NULL);
		pthread_join(thds->observ_tids[i], NULL);
		pthread_mutex_destroy(&(thds->mutexes[i]));
        i++;
    }
    pthread_mutex_destroy(&(thds->msg_mutex));
    free_threads(thds);
}
