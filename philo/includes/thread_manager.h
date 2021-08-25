/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:04:35 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 16:52:33 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_MANAGER_H
# define THREAD_MANAGER_H
# include <stdlib.h>
# include <string.h>
# include "philosopher.h"
# include "observer.h"

void	free_threads(t_threads *thds);
int		thread_manager_err(char *err_msg, t_threads *thds);
int		alloc_threads(t_data *data);
int		init_mutex(t_data *data);
int		create_threads(t_data *data);
void	finish_threads(t_threads *thds, int num_philo);

#endif
