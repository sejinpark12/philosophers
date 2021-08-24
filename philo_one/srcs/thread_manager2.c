/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:09:31 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 16:52:16 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/thread_manager.h"

void	free_threads(t_threads *thds)
{
	free(thds->tids);
	free(thds->observ_tids);
	free(thds->mutexes);
	free(thds->permits);
}

int	thread_manager_err(char *err_msg, t_threads *thds)
{
	free_threads(thds);
	return (print_err(err_msg));
}
