/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:24:19 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/17 15:31:48 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void pickup_forks(t_philo *philo, int fork_idx)
{
    pthread_mutex_t     *mutex;
    int                 *permits;

    mutex = &(philo->thds->mutexes[fork_idx]);
    permits = philo->thds->permits;
	pthread_mutex_lock(mutex);
	if (permits[fork_idx] == 1)
		permits[fork_idx] = 0;
}

void return_forks(t_philo *philo, int fork_idx)
{
    int num_philo;
    int *permits;

    num_philo = philo->opts->num_philo;
    permits = philo->thds->permits;
	permits[fork_idx % num_philo] = 1;
}

void my_sleep(unsigned int time)
{
    t_time start;

    gettimeofday(&start, NULL);
    while (1)
    {
        if (cal_time(&start) > time / 1000)
            return ;
        usleep(1000);
    }
}

void *philosopher(void *arg)
{
	t_philo *philo;
    int     philo_idx;
    int     r_fork;
    int     l_fork;
    long    time_stamp;
    t_time  tmp_last_eat_time;

	philo = (t_philo*)arg;
    philo_idx = philo->philo_idx;
    r_fork = philo->philo_idx % philo->opts->num_philo;
    l_fork = philo->philo_idx - 1;
    my_sleep(philo->opts->time_eat);
	while (!philo->opts->finish)
	{
		// pickup left fork
		pickup_forks(philo, l_fork);
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 1;
        printf("%ld %d has taken a fork\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
		// pickup right fork
		pickup_forks(philo, r_fork);
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 2;
		printf("%ld %d has taken a fork\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        // eating
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        gettimeofday(&tmp_last_eat_time, NULL);
        time_stamp = cal_time(philo->start_time);
        philo->status = 3;
		printf("%ld %d is eating\n", time_stamp, philo_idx);
        philo->last_eat_time = tmp_last_eat_time;
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        my_sleep(philo->opts->time_eat);
		// putdown right fork
		return_forks(philo, r_fork);
		pthread_mutex_unlock(&(philo->thds->mutexes[r_fork]));
		// putdown left fork
		return_forks(philo, l_fork);
		pthread_mutex_unlock(&(philo->thds->mutexes[l_fork]));
        // sleeping
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 4;
		printf("%ld %d is sleeping\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        my_sleep(philo->opts->time_sleep);
        my_sleep(1000);
        // thinking
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 0;
		printf("%ld %d is thinking\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
	}
    pthread_mutex_unlock(&(philo->thds->mutexes[r_fork]));
    pthread_mutex_unlock(&(philo->thds->mutexes[l_fork]));
    pthread_mutex_unlock(&philo->thds->msg_mutex);
	return (NULL);
}

void *oddphilosopher(void *arg)
{
    t_philo *philo;
	int     philo_idx;
    int     r_fork;
    int     l_fork;
    long    time_stamp;
    t_time  tmp_last_eat_time;

    philo = (t_philo*)arg;
    philo_idx = philo->philo_idx;
    r_fork = philo->philo_idx % philo->opts->num_philo;
    l_fork = philo->philo_idx - 1;
    if (philo->philo_idx == philo->opts->num_philo)
        my_sleep(philo->opts->time_eat * 2);
	while (!philo->opts->finish)
	{
		// pickup right fork
		pickup_forks(philo, r_fork);
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 1;
		printf("%ld %d has taken a fork\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        // 철학자가 1명일 경우 끝내는 로직
        if (philo->opts->num_philo == 1)
            break ;
		// pickup left fork
		pickup_forks(philo, l_fork);
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 2;
		printf("%ld %d has taken a fork\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        // eating
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        gettimeofday(&tmp_last_eat_time, NULL);
        time_stamp = cal_time(philo->start_time);
        philo->status = 3;
		printf("%ld %d is eating\n", time_stamp, philo_idx);
        philo->last_eat_time = tmp_last_eat_time;
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        my_sleep(philo->opts->time_eat);
		// putdown left fork
		return_forks(philo, l_fork);
		pthread_mutex_unlock(&(philo->thds->mutexes[l_fork]));
		// putdown right fork
		return_forks(philo, r_fork);
		pthread_mutex_unlock(&(philo->thds->mutexes[r_fork]));
        // sleeping
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 4;
		printf("%ld %d is sleeping\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
        my_sleep(philo->opts->time_sleep);
        my_sleep(1000);
        // thinking
        pthread_mutex_lock(&philo->thds->msg_mutex);
        if (philo->opts->finish)
            break ;
        time_stamp = cal_time(philo->start_time);
        philo->status = 0;
		printf("%ld %d is thinking\n", time_stamp, philo_idx);
        pthread_mutex_unlock(&philo->thds->msg_mutex);
	}
    pthread_mutex_unlock(&(philo->thds->mutexes[r_fork]));
    pthread_mutex_unlock(&(philo->thds->mutexes[l_fork]));
    pthread_mutex_unlock(&philo->thds->msg_mutex);
	return (NULL);
}
