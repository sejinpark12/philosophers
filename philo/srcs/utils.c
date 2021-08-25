/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:13:32 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 16:20:50 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

long	cal_time(t_time *start_time)
{
	t_time	now_time;
	long	result;

	gettimeofday(&now_time, NULL);
	result = (now_time.tv_sec - start_time->tv_sec) * 1000
		+ (now_time.tv_usec - start_time->tv_usec) / 1000;
	return (result);
}

int	print_err(char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	return (1);
}

void	my_sleep(unsigned int time)
{
	t_time	start;

	gettimeofday(&start, NULL);
	while (1)
	{
		if (cal_time(&start) > time / 1000)
			return ;
		usleep(1000);
	}
}
