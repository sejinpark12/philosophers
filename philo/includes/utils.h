/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:12:08 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/24 16:20:19 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "structs.h"
# include "ft_strlen.h"
# include <unistd.h>

long	cal_time(t_time *start_time);
int		print_err(char *err_msg);
void	my_sleep(unsigned int time);

#endif
