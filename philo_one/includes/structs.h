/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:44:47 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/23 13:58:06 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <pthread.h>
# include <sys/time.h>

typedef struct      timeval t_time;
typedef struct      s_options
{
    int             num_philo;
    unsigned int    time_die;
    unsigned int    time_eat;
    unsigned int    time_sleep;
    int             num_each_philo_eat;
    int             finish;
}                   t_options;
typedef struct      s_threads
{
    pthread_t       *tids;
    pthread_t       *observ_tids;
    pthread_mutex_t *mutexes;
    int             *permits;
    pthread_mutex_t msg_mutex;
    pthread_mutex_t complete_mutex;
    int             complete_philo_cnt;
}                   t_threads;
typedef struct      s_philo
{
    int             philo_idx;
    t_time          *start_time;
    t_time          last_eat_time;
    char            status;
    int             eating_cnt;
    t_threads       *thds;
    t_options       *opts;
}                   t_philo;
typedef struct      s_data
{
    t_options       opts;
    t_threads       thds;
    t_time          start_time;
    t_philo         *philos;
}                   t_data;
#endif
